#!/usr/bin/env python3

#
# This file is part of LiteX-M2SDR.
#
# Copyright (c) 2024-2025 Enjoy-Digital <enjoy-digital.fr>
# SPDX-License-Identifier: BSD-2-Clause

import os
import time
import argparse

from migen import *

from litex.gen import *
from litex.gen.genlib.cdc import BusSynchronizer

from litex.build.generic_platform import Subsignal, Pins

from litex.soc.interconnect.csr import *
from litex.soc.interconnect     import stream

from litex.soc.integration.soc_core import *
from litex.soc.integration.builder  import *

from litex.soc.cores.clock     import *
from litex.soc.cores.led       import LedChaser
from litex.soc.cores.icap      import ICAP
from litex.soc.cores.xadc      import XADC
from litex.soc.cores.dna       import DNA
from litex.soc.cores.gpio      import GPIOOut
from litex.soc.cores.spi_flash import S7SPIFlash

from litex.build.generic_platform import IOStandard, Subsignal, Pins

from litepcie.common        import *
from litepcie.phy.s7pciephy import S7PCIEPHY
from litepcie.frontend.ptm  import PCIePTMSniffer
from litepcie.frontend.ptm  import PTMCapabilities, PTMRequester

from liteeth.common           import convert_ip
from liteeth.phy.a7_1000basex import A7_1000BASEX, A7_2500BASEX
from liteeth.frontend.stream  import LiteEthStream2UDPTX, LiteEthUDP2StreamRX

from litesata.phy import LiteSATAPHY

from litescope import LiteScopeAnalyzer

from litex_m2sdr import Platform

from litex_m2sdr.gateware.capability  import Capability
from litex_m2sdr.gateware.si5351      import SI5351
from litex_m2sdr.gateware.si5351_i2c  import SI5351I2C, i2c_program_si5351
from litex_m2sdr.gateware.ad9361.core import AD9361RFIC
from litex_m2sdr.gateware.qpll        import SharedQPLL
from litex_m2sdr.gateware.time        import TimeGenerator
from litex_m2sdr.gateware.pps         import PPSGenerator
from litex_m2sdr.gateware.header      import TXRXHeader
from litex_m2sdr.gateware.measurement import MultiClkMeasurement
from litex_m2sdr.gateware.gpio        import GPIO, GPIORXPacker, GPIOTXUnpacker

from litex_m2sdr.software import generate_litepcie_software

# CRG ----------------------------------------------------------------------------------------------

class CRG(LiteXModule):
    def __init__(self, platform, sys_clk_freq, with_eth=False, with_sata=False, with_white_rabbit=False):
        self.rst              = Signal()
        self.cd_sys           = ClockDomain()
        self.cd_clk10         = ClockDomain()

        self.cd_clk100        = ClockDomain()
        self.cd_idelay        = ClockDomain()

        self.cd_refclk_pcie   = ClockDomain()
        self.cd_refclk_eth    = ClockDomain()
        self.cd_refclk_sata   = ClockDomain()

        self.cd_clk_125m_gtp  = ClockDomain()
        self.cd_clk_62m5_dmtd = ClockDomain()
        self.cd_clk10m_in     = ClockDomain()
        self.cd_clk62m5_in    = ClockDomain()

        # # #

        assert not (with_eth and with_white_rabbit) # FIXME.

        # Clk / Rst.
        # ----------
        clk100 = platform.request("clk100")

        # PLL.
        # ----
        self.pll = pll = S7PLL(speedgrade=-3)
        self.comb += self.pll.reset.eq(self.rst)
        pll.register_clkin(clk100, 100e6)
        pll.create_clkout(self.cd_sys,    sys_clk_freq)
        if not with_white_rabbit:
            pll.create_clkout(self.cd_clk10, 10e6)
        pll.create_clkout(self.cd_idelay, 200e6)
        platform.add_platform_command("set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets basesoc_crg_clkout_buf1]")       # FIXME: Simplify clk10.
        platform.add_platform_command("set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets basesoc_crg_s7pll_clkout_buf1]") # FIXME: Simplify clk10.
        self.comb += self.cd_clk100.clk.eq(pll.clkin)

        # IDelayCtrl.
        # -----------
        self.idelayctrl = S7IDELAYCTRL(self.cd_idelay)

        # Ethernet PLL.
        # -------------
        if with_eth or with_sata:
            self.eth_pll = eth_pll = S7PLL()
            eth_pll.register_clkin(self.cd_sys.clk, sys_clk_freq)
            eth_pll.create_clkout(self.cd_refclk_eth, 156.25e6, margin=0)

        # SATA PLL.
        # ---------
        if with_sata or with_eth:
            self.sata_pll = sata_pll = S7PLL()
            sata_pll.register_clkin(self.cd_sys.clk, sys_clk_freq)
            sata_pll.create_clkout(self.cd_refclk_sata, 150e6, margin=0)

        # White Rabbit MMCMs.
        # -------------------
        if with_white_rabbit:
            # RefClk MMCM (125MHz).
            self.refclk_mmcm = S7MMCM(speedgrade=-3)
            self.comb += self.refclk_mmcm.reset.eq(self.rst)
            self.refclk_mmcm.register_clkin(ClockSignal("clk100"), 100e6)
            self.refclk_mmcm.create_clkout(self.cd_clk_125m_gtp,  125e6, margin=0)
            self.refclk_mmcm.expose_dps("clk100", with_csr=False)
            self.refclk_mmcm.params.update(p_CLKOUT0_USE_FINE_PS="TRUE")
            self.comb += self.cd_refclk_eth.clk.eq(self.cd_clk_125m_gtp.clk)

            # DMTD MMCM (62.5MHz).
            self.dmtd_mmcm = S7MMCM(speedgrade=-3)
            self.comb += self.dmtd_mmcm.reset.eq(self.rst)
            self.dmtd_mmcm.register_clkin(ClockSignal("clk100"), 100e6)
            self.dmtd_mmcm.create_clkout(self.cd_clk_62m5_dmtd, 62.5e6, margin=0)
            self.dmtd_mmcm.expose_dps("clk100", with_csr=False)
            self.dmtd_mmcm.params.update(p_CLKOUT0_USE_FINE_PS="TRUE")

# BaseSoC ------------------------------------------------------------------------------------------

class BaseSoC(SoCMini):
    SoCCore.csr_map = {
        # SoC.
        "ctrl"            : 0,
        "uart"            : 1,
        "icap"            : 2,
        "flash_cs_n"      : 3,
        "xadc"            : 4,
        "dna"             : 5,
        "flash"           : 6,
        "leds"            : 7,
        "identifier_mem"  : 8,
        "timer0"          : 9,

        # Capability.
        "capability"      : 13,

        # Time.
        "time_gen"        : 17,

        # PCIe.
        "pcie_phy"        : 10,
        "pcie_msi"        : 11,
        "pcie_dma0"       : 12,

        # Eth.
        "eth_phy"         : 14,
        "eth_rx_streamer" : 15,
        "eth_tx_streamer" : 16,

        # SATA.
        "sata_phy"        : 18,
        "sata_core"       : 19,

        # SDR.
        "si5351"          : 20,
        "header"          : 23,
        "ad9361"          : 24,
        "crossbar"        : 25,

        # GPIO.
        "gpio"            : 21,

        # Measurements/Analyzer.
        "clk_measurement" : 30,
        "analyzer"        : 31,
    }

    def __init__(self, variant="m2", sys_clk_freq=int(125e6),
        with_pcie              = True,  with_pcie_ptm=False, pcie_lanes=1,
        with_eth               = False, eth_sfp=0, eth_phy="1000basex", eth_local_ip="192.168.1.50", eth_udp_port=2345,
        with_sata              = False, sata_gen="gen2",
        with_white_rabbit      = False,
        with_jtagbone          = True,
        with_rfic_oversampling = False,
    ):
        # Platform ---------------------------------------------------------------------------------

        platform = Platform(build_multiboot=True)
        if (with_eth or with_sata) and (variant != "baseboard"):
            msg = "Ethernet and SATA are only supported when mounted in the LiteX Acorn Baseboard Mini! "
            msg += "Available here: https://enjoy-digital-shop.myshopify.com/products/litex-acorn-baseboard-mini"
            raise ValueError(msg)

        # SoCMini ----------------------------------------------------------------------------------

        SoCMini.__init__(self, platform, sys_clk_freq,
            ident         = f"LiteX-M2SDR SoC / {variant} variant / built on",
            ident_version = True,
        )

        # Clocking ---------------------------------------------------------------------------------

        # General.
        self.crg = CRG(platform, sys_clk_freq,
            with_eth          = with_eth,
            with_sata         = with_sata,
            with_white_rabbit = with_white_rabbit,
        )

        # Shared QPLL.
        self.qpll = SharedQPLL(platform,
            with_pcie       = with_pcie,
            with_eth        = with_eth | with_white_rabbit,
            eth_phy         = eth_phy,
            eth_refclk_freq = {True: 125e6, False: 156.25e6}[with_white_rabbit],
            with_sata       = with_sata,
        )

        # Capability -------------------------------------------------------------------------------

        self.capability = Capability(
            # API Version.
            api_version_str = "1.0",

            # PCIe Capabilities.
            pcie_enabled    = with_pcie,
            pcie_speed      = "gen2",
            pcie_lanes      = pcie_lanes,

            # Ethernet Capabilities.
            eth_enabled     = with_eth,
            eth_speed       = eth_phy,

            # SATA Capabilities.
            sata_enabled    = with_sata,
            sata_gen        = sata_gen,

            # GPIO Capabilities.
            gpio_enabled    = True,
        )

        # SI5351 Clock Generator -------------------------------------------------------------------

        si5351_clk_in = Signal()
        self.si5351 = SI5351(platform, sys_clk_freq=sys_clk_freq, clk_in=si5351_clk_in)
        si5351_clk0 = platform.request("si5351_clk0")
        si5351_clk1 = platform.request("si5351_clk1")

        # Time Generator ---------------------------------------------------------------------------

        self.time_gen = TimeGenerator(
            clk        = si5351_clk1,
            clk_freq   = 100e6,
            with_csr   = True,
        )

        # FIXME: Try to avoid CDC, change sys_clk?
        time_sys = Signal(64)
        self.time_sync = BusSynchronizer(
            width   = 64,
            idomain = "time",
            odomain = "sys",
        )
        self.comb += [
            self.time_sync.i.eq(self.time_gen.time),
            time_sys.eq(self.time_sync.o),
        ]

        # PPS Generator ----------------------------------------------------------------------------

        self.pps_gen = ClockDomainsRenamer("time")(PPSGenerator(
            clk_freq = 100e6,
            time     = self.time_gen.time,
            reset    = self.time_gen.time_change,
        ))
        # FIXME: Improve.
        pps_sys   = Signal()
        pps_sys_d = Signal()
        pps_rise  = Signal()
        self.specials += MultiReg(self.pps_gen.pps, pps_sys)
        self.sync += pps_sys_d.eq(pps_sys)
        self.comb += pps_rise.eq(pps_sys & ~pps_sys_d)

        # JTAGBone ---------------------------------------------------------------------------------

        if with_jtagbone:
            self.add_jtagbone()
            platform.add_period_constraint(self.jtagbone_phy.cd_jtag.clk, 1e9/20e6)

        # Leds -------------------------------------------------------------------------------------

        led_pad = platform.request("user_led")
        self.leds = LedChaser(pads=Signal(), sys_clk_freq=sys_clk_freq)
        self.sync += led_pad.eq(self.leds.pads)

        # ICAP -------------------------------------------------------------------------------------

        self.icap = ICAP()
        self.icap.add_reload()
        self.icap.add_timing_constraints(platform, sys_clk_freq, self.crg.cd_sys.clk)

        # XADC -------------------------------------------------------------------------------------

        self.xadc = XADC()

        # DNA --------------------------------------------------------------------------------------

        self.dna = DNA()
        self.dna.add_timing_constraints(platform, sys_clk_freq, self.crg.cd_sys.clk)

        # SPI Flash --------------------------------------------------------------------------------

        self.flash_cs_n = GPIOOut(platform.request("flash_cs_n"))
        self.flash      = S7SPIFlash(platform.request("flash"), sys_clk_freq, 25e6)
        self.add_config("FLASH_IMAGE_SIZE", platform.image_size)

        # PCIe -------------------------------------------------------------------------------------

        if with_pcie:
            if variant == "baseboard":
                assert pcie_lanes == 1
            pcie_dmas = 1
            self.pcie_phy = S7PCIEPHY(platform, platform.request(f"pcie_x{pcie_lanes}_{variant}"),
                data_width  = {1: 64, 2: 64, 4: 128}[pcie_lanes],
                bar0_size   = 0x20000,
                with_ptm    = with_pcie_ptm,
                cd          = "sys",
            )
            self.comb += ClockSignal("refclk_pcie").eq(self.pcie_phy.pcie_refclk)
            if variant == "baseboard":
                platform.toolchain.pre_placement_commands.append("reset_property LOC [get_cells -hierarchical -filter {{NAME=~pcie_s7/*gtp_channel.gtpe2_channel_i}}]")
                platform.toolchain.pre_placement_commands.append("set_property LOC GTPE2_CHANNEL_X0Y4 [get_cells -hierarchical -filter {{NAME=~pcie_s7/*gtp_channel.gtpe2_channel_i}}]")
            self.pcie_phy.update_config({
                "Base_Class_Menu"          : "Wireless_controller",
                "Sub_Class_Interface_Menu" : "RF_controller",
                "Class_Code_Base"          : "0D",
                "Class_Code_Sub"           : "10",
                }
            )
            self.add_pcie(phy=self.pcie_phy, address_width=64, ndmas=pcie_dmas, data_width=64,
                with_dma_buffering    = True, dma_buffering_depth=8192,
                with_dma_loopback     = True,
                with_dma_synchronizer = True,
                with_msi              = True,
                with_ptm              = with_pcie_ptm,
            )
            self.pcie_phy.use_external_qpll(qpll_channel=self.qpll.get_channel("pcie"))
            self.comb += self.pcie_dma0.synchronizer.pps.eq(pps_rise)
            if with_pcie_ptm:
                # TODO:
                # - Connect Time.
                # - Integrate Driver.
                # - Test phc2sys Host <-> Board regulation.
                if pcie_lanes != 1:
                    raise NotImplementedError("PCIe PTM only supported in PCIe Gen2 X1 for now.")
                from litex_wr_nic.gateware.soc import LiteXWRNICSoC
                LiteXWRNICSoC.add_pcie_ptm(self)

        # Ethernet ---------------------------------------------------------------------------------

        if with_eth:
            # PHY.
            eth_phy_cls = {
                "1000basex" : A7_1000BASEX,
                "2500basex" : A7_2500BASEX,
            }[eth_phy]
            self.eth_phy = eth_phy_cls(
                qpll_channel = self.qpll.get_channel("eth"),
                data_pads    = self.platform.request("sfp", eth_sfp),
                sys_clk_freq = sys_clk_freq,
                rx_polarity  = 1, # Inverted on M2SDR.
                tx_polarity  = 0, # Inverted on M2SDR and Acorn Baseboard Mini.
            )
            platform.add_period_constraint(self.eth_phy.txoutclk, 1e9/(self.eth_phy.tx_clk_freq/2))
            platform.add_period_constraint(self.eth_phy.rxoutclk, 1e9/(self.eth_phy.tx_clk_freq/2))

            # Core + MMAP (Etherbone).
            self.add_etherbone(phy=self.eth_phy, ip_address=eth_local_ip, data_width=32, arp_entries=4)

            # UDP Streamer.
            eth_streamer_port = self.ethcore_etherbone.udp.crossbar.get_port(eth_udp_port, dw=64, cd="sys")

            # RFIC -> UDP TX.
            self.eth_rx_streamer = LiteEthStream2UDPTX(
                udp_port   = eth_udp_port,
                fifo_depth = 1024//8,
                data_width = 64,
                with_csr   = True,
            )
            self.comb += self.eth_rx_streamer.source.connect(eth_streamer_port.sink)

            # UDP RX -> RFIC.
            self.eth_tx_streamer = LiteEthUDP2StreamRX(
                udp_port   = eth_udp_port,
                fifo_depth = 1024//8,
                data_width = 64,
                with_csr   = True,
            )
            self.comb += eth_streamer_port.source.connect(self.eth_tx_streamer.sink)

        # SATA -------------------------------------------------------------------------------------

        if with_sata:
            # IOs
            _sata_io = [
                ("sata", 0,
                    # Inverted on M2SDR.
                    Subsignal("tx_p",  Pins("D7")),
                    Subsignal("tx_n",  Pins("C7")),
                    # Inverted on M2SDR.
                    Subsignal("rx_p",  Pins("D9")),
                    Subsignal("rx_n",  Pins("C9")),
                ),
            ]
            platform.add_extension(_sata_io)

            # PHY
            self.sata_phy = LiteSATAPHY(platform.device,
                refclk     = ClockSignal("refclk_sata"),
                pads       = platform.request("sata"),
                gen        = sata_gen,
                clk_freq   = sys_clk_freq,
                data_width = 16,
                qpll       = self.qpll.get_channel("sata"),
            )

            # Core
            self.add_sata(phy=self.sata_phy, mode="read+write")

        # AD9361 RFIC ------------------------------------------------------------------------------

        self.ad9361 = AD9361RFIC(
            rfic_pads    = platform.request("ad9361_rfic"),
            spi_pads     = platform.request("ad9361_spi"),
            sys_clk_freq = sys_clk_freq,
        )
        self.ad9361.add_prbs()
        self.ad9361.add_agc()
        rfic_clk_freq = {
            False : 245.76e6, # Max rfic_clk for  61.44MSPS / 2T2R.
            True  : 491.52e6, # Max rfic_clk for 122.88MSPS / 2T2R (Oversampling).
        }[with_rfic_oversampling]
        self.platform.add_period_constraint(self.ad9361.cd_rfic.clk, 1e9/rfic_clk_freq)

        # TX/RX Header Extracter/Inserter ----------------------------------------------------------

        self.header = TXRXHeader(data_width=64)
        self.comb += [
            self.header.rx.header.eq(0x5aa5_5aa5_5aa5_5aa5), # Unused for now, arbitrary.
            self.header.rx.timestamp.eq(time_sys),
        ]

        # TX/RX Datapath ---------------------------------------------------------------------------

        # AD9361 <-> Header.
        # ------------------
        self.comb += [
            self.header.tx.source.connect(self.ad9361.sink),
            self.ad9361.source.connect(self.header.rx.sink),
        ]

        # Crossbar.
        # ---------
        self.crossbar = stream.Crossbar(layout=dma_layout(64), n=3, with_csr=True)

        # TX: Comms -> Crossbar -> Header.
        # --------------------------------
        if with_pcie:
            self.comb += [
                self.pcie_dma0.source.connect(self.crossbar.mux.sink0),
                If(self.crossbar.mux.sel == 0,
                    self.header.tx.reset.eq(~self.pcie_dma0.synchronizer.synced)
                )
            ]
        if with_eth:
            self.comb += self.eth_tx_streamer.source.connect(self.crossbar.mux.sink1, omit={"error"})
        if with_sata:
            pass # TODO.
        self.comb += self.crossbar.mux.source.connect(self.header.tx.sink)

        # RX: Header -> Crossbar -> Comms.
        # --------------------------------
        self.comb += self.header.rx.source.connect(self.crossbar.demux.sink)
        if with_pcie:
            self.comb += [
                self.crossbar.demux.source0.connect(self.pcie_dma0.sink),
                If(self.crossbar.demux.sel == 0,
                    self.header.rx.reset.eq(~self.pcie_dma0.synchronizer.synced)
                )
            ]
        if with_eth:
            self.comb += self.crossbar.demux.source1.connect(self.eth_rx_streamer.sink)
        if with_sata:
            pass # TODO.

        # GPIO -------------------------------------------------------------------------------------

        self.gpio = GPIO(
            rx_packer   = self.ad9361.gpio_rx_packer,
            tx_unpacker = self.ad9361.gpio_tx_unpacker,
        )
        # GPIO0   : Sync/ClkIn.
        # GPIO1-3 : Synchro_GPIO1-3.
        self.gpio.connect_to_pads(pads=platform.request("gpios"))

        # Drive led from GPIO0 when in loopback mode to ease test/verification.
        self.sync += If(self.gpio._control.fields.loopback, led_pad.eq(self.gpio.i_async[0]))

        # Use GPIO0 as ClkIn.
        self.comb += si5351_clk_in.eq(self.gpio.i_async[0])

        # White Rabbit -----------------------------------------------------------------------------

        if with_white_rabbit:

            from litex.soc.cores.uart import UARTPHY, UART

            from litex_wr_nic.gateware.soc  import LiteXWRNICSoC

            # IOs.
            # ----

            _sfp_i2c_io = [
                ("sfp_i2c", 0,
                    Subsignal("sda",  Pins("M2:SMB_DAT")),
                    Subsignal("scl",  Pins("M2:SMB_CLK")),
                    IOStandard("LVCMOS33"),
                ),
            ]
            platform.add_extension(_sfp_i2c_io)

            # UART.
            # -----

            class UARTPads:
                def __init__(self):
                    self.tx = Signal()
                    self.rx = Signal()

            self.uart_xover_pads = UARTPads()
            self.shared_pads     = UARTPads()
            self.uart_xover_phy  = UARTPHY(self.uart_xover_pads, clk_freq=sys_clk_freq, baudrate=115200)
            self.uart_xover      = UART(self.uart_xover_phy, rx_fifo_depth=128, rx_fifo_rx_we=True)

            self.comb += [
                self.uart_xover_pads.rx.eq(self.shared_pads.tx),
                self.shared_pads.rx.eq(self.uart_xover_pads.tx),
            ]

            # Core Instance.
            # --------------
            sfp_i2c_pads = platform.request("sfp_i2c")
            LiteXWRNICSoC.add_wr_core(self,
                # CPU.
                cpu_firmware    = "../litex_wr_nic/litex_wr_nic/firmware/spec_a7_wrc.bram", # FIXME: Avoid hardcoded path.

                # Board name.
                board_name       = "SAWR",

                # SFP.
                sfp_pads        = platform.request("sfp", 0),
                sfp_i2c_pads    = sfp_i2c_pads,
                sfp_tx_polarity = 0, # Inverted on M2SDR and Acorn Baseboard Mini.
                sfp_rx_polarity = 1, # Inverted on M2SDR.

                # QPLL.
                qpll            = self.qpll,
                with_ext_clk    = False,

                # Serial.
                serial_pads     = self.shared_pads,
            )
            LiteXWRNICSoC.add_sources(self)

            # Clk10M Generator.
            # -----------------

            self.syncout_pll = syncout_pll = S7MMCM(speedgrade=-2)
            self.comb += syncout_pll.reset.eq(ResetSignal("wr"))
            syncout_pll.register_clkin(ClockSignal("wr"), 62.5e6)
            syncout_pll.create_clkout(self.crg.cd_clk10, 10e6, margin=0, phase=0)

            # RefClk MMCM Phase Shift.
            # ------------------------
            self.refclk_mmcm_ps_gen = Instance("ps_gen",
                p_WIDTH       = 16,
                p_DIV         = 16,
                p_MULT        = 7,

                i_pswidth     = self.dac_refclk_data,
                i_pswidth_set = self.dac_refclk_load,
                i_pswidth_clk = ClockSignal("wr"),

                i_psclk       = ClockSignal("clk100"),
                i_psdone      = self.crg.refclk_mmcm.psdone,
                o_psen        = self.crg.refclk_mmcm.psen,
                o_psincdec    = self.crg.refclk_mmcm.psincdec,
            )

            # DMTD MMCM Phase Shift.
            # ----------------------
            self.dac_mmcm_ps_gen = Instance("ps_gen",
                p_WIDTH       = 16,
                p_DIV         = 16,
                p_MULT        = 7,

                i_pswidth     = self.dac_dmtd_data,
                i_pswidth_set = self.dac_dmtd_load,
                i_pswidth_clk = ClockSignal("wr"),

                i_psclk       = ClockSignal("clk100"),
                i_psdone      = self.crg.dmtd_mmcm.psdone,
                o_psen        = self.crg.dmtd_mmcm.psen,
                o_psincdec    = self.crg.dmtd_mmcm.psincdec,
            )

            # Timings Constraints.
            # --------------------
            platform.add_platform_command("set_property SEVERITY {{Warning}} [get_drc_checks REQP-123]") # FIXME: Add 10MHz Ext Clk.
            platform.add_platform_command("create_clock -name wr_txoutclk -period 16.000 [get_pins -hierarchical *gtpe2_i/TXOUTCLK]")
            platform.add_platform_command("create_clock -name wr_rxoutclk -period 16.000 [get_pins -hierarchical *gtpe2_i/RXOUTCLK]")


        # Timing Constraints/False Paths -----------------------------------------------------------


        if with_white_rabbit:
            platform.add_false_path_constraints(
                # PCIe.
                #"main_s7pciephy_clkout0", # FIXME.
                #"main_s7pciephy_clkout1", # FIXME.
                #"main_s7pciephy_clkout2", # FIXME.
                #"main_s7pciephy_clkout3", # FIXME.

                # CRG.
                "clk100",
                "clk_sys",
                "{{*crg_s7pll_clkout0}}",
                "{{*crg_s7pll_clkout1}}",

                # RFIC.
                "rfic_clk",

                # Internal Primitives.
                "dna_clk",
                "jtag_clk",
                "icap_clk",

                # Sync.
                "si5351_clk0",
                "si5351_clk1",
                "sync_clk_in",

                # White Rabbit.
                "wr_rxoutclk",
                "wr_txoutclk",
                "{{*crg_s7mmcm0_clkout}}",
                "{{*crg_s7mmcm1_clkout}}",
            )
        else:
            platform.add_false_path_constraints(
                # PCIe.
                #"main_s7pciephy_clkout0", # FIXME.
                #"main_s7pciephy_clkout1", # FIXME.
                #"main_s7pciephy_clkout2", # FIXME.
                #"main_s7pciephy_clkout3", # FIXME.

                # CRG.
                "clk100",
                "{{*crg_clkout0}}",
                "{{*crg_clkout1}}",

                # RFIC.
                "rfic_clk",

                # Internal Primitives.
                "dna_clk",
                "jtag_clk",
                "icap_clk",

                # Sync.
                "si5351_clk0",
                "si5351_clk1",
                "sync_clk_in",
            )

        platform.add_platform_command("set_property CLOCK_DEDICATED_ROUTE FALSE [get_nets {{*crg_s7pll0_clkout_buf1}}]")

        # Clk Measurements -------------------------------------------------------------------------

        self.clk_measurement = MultiClkMeasurement(clks={
            "clk0" : ClockSignal("sys"),
            "clk1" : 0 if not with_pcie else ClockSignal("pcie"),
            "clk2" : si5351_clk0,
            "clk3" : ClockSignal("rfic"),
            "clk4" : si5351_clk1,
        })

    # LiteScope Probes (Debug) ---------------------------------------------------------------------

    def add_ad9361_spi_probe(self):
        analyzer_signals = [self.platform.lookup_request("ad9361_spi")]
        self.analyzer = LiteScopeAnalyzer(analyzer_signals,
            depth        = 4096,
            clock_domain = "sys",
            register     = True,
            csr_csv      = "analyzer.csv"
        )

    def add_ad96361_data_probe(self):
        analyzer_signals = [
            self.ad9361.phy.sink,   # TX.
            self.ad9361.phy.source, # RX.
            self.ad9361.prbs_rx.fields.synced,
        ]
        self.analyzer = LiteScopeAnalyzer(analyzer_signals,
            depth        = 4096,
            clock_domain = "rfic",
            register     = True,
            csr_csv      = "analyzer.csv"
        )

    def add_pcie_dma_probe(self):
        assert hasattr(self, "pcie_dma0")
        analyzer_signals = [
            self.pps_gen.pps,      # PPS.
            self.pcie_dma0.sink,   # RX.
            self.pcie_dma0.source, # TX.
            self.pcie_dma0.synchronizer.synced,
            self.header.rx.reset,
            self.header.tx.reset,
        ]
        self.analyzer = LiteScopeAnalyzer(analyzer_signals,
            depth        = 1024,
            clock_domain = "sys",
            register     = True,
            csr_csv      = "analyzer.csv"
        )

    def add_eth_tx_probe(self):
        assert hasattr(self, "eth_streamer")
        analyzer_signals = [
            self.eth_streamer.sink,
        ]
        self.analyzer = LiteScopeAnalyzer(analyzer_signals,
            depth        = 1024,
            clock_domain = "sys",
            register     = True,
            csr_csv      = "analyzer.csv"
        )

# Build --------------------------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(description="LiteX SoC on LiteX-M2SDR.", formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    # Build/Load/Utilities.
    parser.add_argument("--variant",         default="m2",        help="Design variant.", choices=["m2", "baseboard"])
    parser.add_argument("--reset",           action="store_true", help="Reset the device.")
    parser.add_argument("--build",           action="store_true", help="Build bitstream.")
    parser.add_argument("--load",            action="store_true", help="Load bitstream.")
    parser.add_argument("--flash",           action="store_true", help="Flash bitstream.")
    parser.add_argument("--flash-multiboot", action="store_true", help="Flash multiboot bitstreams.")
    parser.add_argument("--rescan",          action="store_true", help="Execute PCIe Rescan while Loading/Flashing.")
    parser.add_argument("--driver",          action="store_true", help="Generate PCIe driver from LitePCIe (override local version).")

    # PCIe parameters.
    parser.add_argument("--with-pcie",       action="store_true", help="Enable PCIe Communication.")
    parser.add_argument("--with-pcie-ptm",   action="store_true", help="Enable PCIe PTM.")
    parser.add_argument("--pcie-lanes",      default=1, type=int, help="PCIe Lanes.", choices=[1, 2, 4])

    # Ethernet parameters.
    parser.add_argument("--with-eth",        action="store_true",     help="Enable Ethernet Communication.")
    parser.add_argument("--eth-sfp",         default=0, type=int,     help="Ethernet SFP.", choices=[0, 1])
    parser.add_argument("--eth-phy",         default="1000basex",     help="Ethernet PHY.", choices=["1000basex", "2500basex"])
    parser.add_argument("--eth-local-ip",    default="192.168.1.50",  help="Ethernet/Etherbone IP address.")
    parser.add_argument("--eth-udp-port",    default=2345, type=int,  help="Ethernet Remote port.")

    # SATA parameters.
    parser.add_argument("--with-sata",       action="store_true",     help="Enable SATA Storage.")

    # White Rabbit parameters.
    parser.add_argument("--with-white-rabbit", action="store_true",     help="Enable White-Rabbit Support (on SFP0).")

    # Litescope Analyzer Probes.
    probeopts = parser.add_mutually_exclusive_group()
    probeopts.add_argument("--with-ad9361-spi-probe",      action="store_true", help="Enable AD9361 SPI Probe.")
    probeopts.add_argument("--with-ad9361-data-probe",     action="store_true", help="Enable AD9361 Data Probe.")
    probeopts.add_argument("--with-pcie-dma-probe",        action="store_true", help="Enable PCIe DMA Probe.")
    probeopts.add_argument("--with-eth-tx-probe",          action="store_true", help="Enable Ethernet Tx Probe.")

    args = parser.parse_args()

    # Build White Rabbit Firmware.
    if args.with_white_rabbit & args.build:
        print("Building White Rabbit firmware...")
        r = os.system("cd ../litex_wr_nic/litex_wr_nic/firmware && ./build.py --target acorn") # FIXME: Avoid harcoded path/platform.
        if r != 0:
            raise RuntimeError("White Rabbit Firmware build failed.")

    # Build SoC.
    soc = BaseSoC(
        # Generic.
        variant       = args.variant,

        # PCIe.
        with_pcie     = args.with_pcie,
        with_pcie_ptm = args.with_pcie_ptm,
        pcie_lanes    = args.pcie_lanes,

        # Ethernet.
        with_eth      = args.with_eth,
        eth_sfp       = args.eth_sfp,
        eth_phy       = args.eth_phy,
        eth_local_ip  = args.eth_local_ip,
        eth_udp_port  = args.eth_udp_port,

        # SATA.
        with_sata     = args.with_sata,

        # White Rabbit.
        with_white_rabbit = args.with_white_rabbit,
    )

    # LiteScope Analyzer Probes.
    if args.with_ad9361_spi_probe:
        soc.add_ad9361_spi_probe()
    if args.with_ad9361_data_probe:
        soc.add_ad96361_data_probe()
    if args.with_pcie_dma_probe:
        soc.add_pcie_dma_probe()
    if args.with_eth_tx_probe:
        soc.add_eth_tx_probe()

    # Builder.
    def get_build_name():
        r = f"litex_m2sdr_{args.variant}"
        if args.with_pcie:
            r += f"_pcie_x{args.pcie_lanes}"
        if args.with_eth:
            r += f"_eth"
        if args.with_white_rabbit:
            r += f"_white_rabbit"
        return r

    builder = Builder(soc, output_dir=os.path.join("build", get_build_name()), csr_csv="csr.csv")
    builder.build(build_name=get_build_name(), run=args.build)

    # Generate LitePCIe Driver.
    generate_litepcie_software(soc, "litex_m2sdr/software", use_litepcie_software=args.driver)

    # Reset Device.
    if args.reset:
        prog = soc.platform.create_programmer()
        prog.reset()
    
    # Load Bistream.
    if args.load:
        prog = soc.platform.create_programmer()
        prog.load_bitstream(os.path.join(builder.gateware_dir, soc.build_name + ".bit"))

    # Flash Bitstream.
    if args.flash:
        prog = soc.platform.create_programmer()
        prog.flash(0, os.path.join(builder.gateware_dir, soc.build_name + ".bin"))

    # Flash Multiboot Bitstreams.
    if args.flash_multiboot:
        prog = soc.platform.create_programmer()
        prog.flash(            0x0000_0000,  builder.get_bitstream_filename(mode="flash").replace(".bin", "_fallback.bin"),    verify=True)
        prog.flash(soc.platform.image_size,  builder.get_bitstream_filename(mode="flash").replace(".bin", "_operational.bin"), verify=True)

    # Rescan PCIe Bus.
    if args.rescan:
        subprocess.run("sudo sh -c 'cd litex_m2sdr/software && ./rescan.py'", shell=True)

if __name__ == "__main__":
    main()
