//--------------------------------------------------------------------------------
// Auto-generated by LiteX (e6c63abe2) on 2025-04-07 16:21:31
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// CSR Includes.
//--------------------------------------------------------------------------------

#ifndef __GENERATED_CSR_H
#define __GENERATED_CSR_H

//--------------------------------------------------------------------------------
// CSR Registers/Fields Definition.
//--------------------------------------------------------------------------------

/* CTRL Registers */
#define CSR_CTRL_BASE 0x0L
#define CSR_CTRL_RESET_ADDR 0x0L
#define CSR_CTRL_RESET_SIZE 1
#define CSR_CTRL_SCRATCH_ADDR 0x4L
#define CSR_CTRL_SCRATCH_SIZE 1
#define CSR_CTRL_BUS_ERRORS_ADDR 0x8L
#define CSR_CTRL_BUS_ERRORS_SIZE 1

/* CTRL Fields */
#define CSR_CTRL_RESET_SOC_RST_OFFSET 0
#define CSR_CTRL_RESET_SOC_RST_SIZE 1
#define CSR_CTRL_RESET_CPU_RST_OFFSET 1
#define CSR_CTRL_RESET_CPU_RST_SIZE 1

/* ICAP Registers */
#define CSR_ICAP_BASE 0x1000L
#define CSR_ICAP_ADDR_ADDR 0x1000L
#define CSR_ICAP_ADDR_SIZE 1
#define CSR_ICAP_DATA_ADDR 0x1004L
#define CSR_ICAP_DATA_SIZE 1
#define CSR_ICAP_WRITE_ADDR 0x1008L
#define CSR_ICAP_WRITE_SIZE 1
#define CSR_ICAP_DONE_ADDR 0x100cL
#define CSR_ICAP_DONE_SIZE 1
#define CSR_ICAP_READ_ADDR 0x1010L
#define CSR_ICAP_READ_SIZE 1

/* ICAP Fields */

/* FLASH_CS_N Registers */
#define CSR_FLASH_CS_N_BASE 0x1800L
#define CSR_FLASH_CS_N_OUT_ADDR 0x1800L
#define CSR_FLASH_CS_N_OUT_SIZE 1

/* FLASH_CS_N Fields */

/* XADC Registers */
#define CSR_XADC_BASE 0x2000L
#define CSR_XADC_TEMPERATURE_ADDR 0x2000L
#define CSR_XADC_TEMPERATURE_SIZE 1
#define CSR_XADC_VCCINT_ADDR 0x2004L
#define CSR_XADC_VCCINT_SIZE 1
#define CSR_XADC_VCCAUX_ADDR 0x2008L
#define CSR_XADC_VCCAUX_SIZE 1
#define CSR_XADC_VCCBRAM_ADDR 0x200cL
#define CSR_XADC_VCCBRAM_SIZE 1
#define CSR_XADC_EOC_ADDR 0x2010L
#define CSR_XADC_EOC_SIZE 1
#define CSR_XADC_EOS_ADDR 0x2014L
#define CSR_XADC_EOS_SIZE 1

/* XADC Fields */

/* DNA Registers */
#define CSR_DNA_BASE 0x2800L
#define CSR_DNA_ID_ADDR 0x2800L
#define CSR_DNA_ID_SIZE 2

/* DNA Fields */

/* FLASH Registers */
#define CSR_FLASH_BASE 0x3000L
#define CSR_FLASH_SPI_CONTROL_ADDR 0x3000L
#define CSR_FLASH_SPI_CONTROL_SIZE 1
#define CSR_FLASH_SPI_STATUS_ADDR 0x3004L
#define CSR_FLASH_SPI_STATUS_SIZE 1
#define CSR_FLASH_SPI_MOSI_ADDR 0x3008L
#define CSR_FLASH_SPI_MOSI_SIZE 2
#define CSR_FLASH_SPI_MISO_ADDR 0x3010L
#define CSR_FLASH_SPI_MISO_SIZE 2
#define CSR_FLASH_SPI_CS_ADDR 0x3018L
#define CSR_FLASH_SPI_CS_SIZE 1
#define CSR_FLASH_SPI_LOOPBACK_ADDR 0x301cL
#define CSR_FLASH_SPI_LOOPBACK_SIZE 1

/* FLASH Fields */
#define CSR_FLASH_SPI_CONTROL_START_OFFSET 0
#define CSR_FLASH_SPI_CONTROL_START_SIZE 1
#define CSR_FLASH_SPI_CONTROL_LENGTH_OFFSET 8
#define CSR_FLASH_SPI_CONTROL_LENGTH_SIZE 8
#define CSR_FLASH_SPI_STATUS_DONE_OFFSET 0
#define CSR_FLASH_SPI_STATUS_DONE_SIZE 1
#define CSR_FLASH_SPI_STATUS_MODE_OFFSET 1
#define CSR_FLASH_SPI_STATUS_MODE_SIZE 1
#define CSR_FLASH_SPI_CS_SEL_OFFSET 0
#define CSR_FLASH_SPI_CS_SEL_SIZE 1
#define CSR_FLASH_SPI_CS_MODE_OFFSET 16
#define CSR_FLASH_SPI_CS_MODE_SIZE 1
#define CSR_FLASH_SPI_LOOPBACK_MODE_OFFSET 0
#define CSR_FLASH_SPI_LOOPBACK_MODE_SIZE 1

/* LEDS Registers */
#define CSR_LEDS_BASE 0x3800L
#define CSR_LEDS_OUT_ADDR 0x3800L
#define CSR_LEDS_OUT_SIZE 1

/* LEDS Fields */

/* IDENTIFIER_MEM Registers */
#define CSR_IDENTIFIER_MEM_BASE 0x4000L

/* IDENTIFIER_MEM Fields */

/* PCIE_PHY Registers */
#define CSR_PCIE_PHY_BASE 0x5000L
#define CSR_PCIE_PHY_PHY_LINK_STATUS_ADDR 0x5000L
#define CSR_PCIE_PHY_PHY_LINK_STATUS_SIZE 1
#define CSR_PCIE_PHY_PHY_MSI_ENABLE_ADDR 0x5004L
#define CSR_PCIE_PHY_PHY_MSI_ENABLE_SIZE 1
#define CSR_PCIE_PHY_PHY_MSIX_ENABLE_ADDR 0x5008L
#define CSR_PCIE_PHY_PHY_MSIX_ENABLE_SIZE 1
#define CSR_PCIE_PHY_PHY_BUS_MASTER_ENABLE_ADDR 0x500cL
#define CSR_PCIE_PHY_PHY_BUS_MASTER_ENABLE_SIZE 1
#define CSR_PCIE_PHY_PHY_MAX_REQUEST_SIZE_ADDR 0x5010L
#define CSR_PCIE_PHY_PHY_MAX_REQUEST_SIZE_SIZE 1
#define CSR_PCIE_PHY_PHY_MAX_PAYLOAD_SIZE_ADDR 0x5014L
#define CSR_PCIE_PHY_PHY_MAX_PAYLOAD_SIZE_SIZE 1

/* PCIE_PHY Fields */
#define CSR_PCIE_PHY_PHY_LINK_STATUS_STATUS_OFFSET 0
#define CSR_PCIE_PHY_PHY_LINK_STATUS_STATUS_SIZE 1
#define CSR_PCIE_PHY_PHY_LINK_STATUS_RATE_OFFSET 1
#define CSR_PCIE_PHY_PHY_LINK_STATUS_RATE_SIZE 1
#define CSR_PCIE_PHY_PHY_LINK_STATUS_WIDTH_OFFSET 2
#define CSR_PCIE_PHY_PHY_LINK_STATUS_WIDTH_SIZE 2
#define CSR_PCIE_PHY_PHY_LINK_STATUS_LTSSM_OFFSET 4
#define CSR_PCIE_PHY_PHY_LINK_STATUS_LTSSM_SIZE 6

/* PCIE_MSI Registers */
#define CSR_PCIE_MSI_BASE 0x5800L
#define CSR_PCIE_MSI_ENABLE_ADDR 0x5800L
#define CSR_PCIE_MSI_ENABLE_SIZE 1
#define CSR_PCIE_MSI_CLEAR_ADDR 0x5804L
#define CSR_PCIE_MSI_CLEAR_SIZE 1
#define CSR_PCIE_MSI_VECTOR_ADDR 0x5808L
#define CSR_PCIE_MSI_VECTOR_SIZE 1

/* PCIE_MSI Fields */

/* PCIE_DMA0 Registers */
#define CSR_PCIE_DMA0_BASE 0x6000L
#define CSR_PCIE_DMA0_WRITER_ENABLE_ADDR 0x6000L
#define CSR_PCIE_DMA0_WRITER_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDR 0x6004L
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_SIZE 2
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_ADDR 0x600cL
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_PROG_N_ADDR 0x6010L
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_PROG_N_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_ADDR 0x6014L
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_LEVEL_ADDR 0x6018L
#define CSR_PCIE_DMA0_WRITER_TABLE_LEVEL_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_RESET_ADDR 0x601cL
#define CSR_PCIE_DMA0_WRITER_TABLE_RESET_SIZE 1
#define CSR_PCIE_DMA0_READER_ENABLE_ADDR 0x6020L
#define CSR_PCIE_DMA0_READER_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDR 0x6024L
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_SIZE 2
#define CSR_PCIE_DMA0_READER_TABLE_WE_ADDR 0x602cL
#define CSR_PCIE_DMA0_READER_TABLE_WE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_PROG_N_ADDR 0x6030L
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_PROG_N_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_ADDR 0x6034L
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_LEVEL_ADDR 0x6038L
#define CSR_PCIE_DMA0_READER_TABLE_LEVEL_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_RESET_ADDR 0x603cL
#define CSR_PCIE_DMA0_READER_TABLE_RESET_SIZE 1
#define CSR_PCIE_DMA0_LOOPBACK_ENABLE_ADDR 0x6040L
#define CSR_PCIE_DMA0_LOOPBACK_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_SYNCHRONIZER_BYPASS_ADDR 0x6044L
#define CSR_PCIE_DMA0_SYNCHRONIZER_BYPASS_SIZE 1
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_ADDR 0x6048L
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_ADDR 0x604cL
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_ADDR 0x6050L
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_ADDR 0x6054L
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_ADDR 0x6058L
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_SIZE 1

/* PCIE_DMA0 Fields */
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDRESS_LSB_OFFSET 0
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDRESS_LSB_SIZE 32
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LENGTH_OFFSET 32
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LENGTH_SIZE 24
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_IRQ_DISABLE_OFFSET 56
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_IRQ_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LAST_DISABLE_OFFSET 57
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LAST_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_ADDRESS_MSB_OFFSET 0
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_ADDRESS_MSB_SIZE 32
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_INDEX_OFFSET 0
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_INDEX_SIZE 16
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_COUNT_OFFSET 16
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_COUNT_SIZE 16
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDRESS_LSB_OFFSET 0
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDRESS_LSB_SIZE 32
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LENGTH_OFFSET 32
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LENGTH_SIZE 24
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_IRQ_DISABLE_OFFSET 56
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_IRQ_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LAST_DISABLE_OFFSET 57
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LAST_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_WE_ADDRESS_MSB_OFFSET 0
#define CSR_PCIE_DMA0_READER_TABLE_WE_ADDRESS_MSB_SIZE 32
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_INDEX_OFFSET 0
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_INDEX_SIZE 16
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_COUNT_OFFSET 16
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_COUNT_SIZE 16
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_MODE_OFFSET 0
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_MODE_SIZE 2
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_DEPTH_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_DEPTH_SIZE 24
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_SCRATCH_OFFSET 24
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_SCRATCH_SIZE 4
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_LEVEL_MODE_OFFSET 31
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_LEVEL_MODE_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_LEVEL_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_LEVEL_SIZE 24
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_DEPTH_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_DEPTH_SIZE 24
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_SCRATCH_OFFSET 24
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_SCRATCH_SIZE 4
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_LEVEL_MODE_OFFSET 31
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_LEVEL_MODE_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_LEVEL_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_LEVEL_SIZE 24

/* CAPABILITY Registers */
#define CSR_CAPABILITY_BASE 0x6800L
#define CSR_CAPABILITY_API_VERSION_ADDR 0x6800L
#define CSR_CAPABILITY_API_VERSION_SIZE 1
#define CSR_CAPABILITY_FEATURES_ADDR 0x6804L
#define CSR_CAPABILITY_FEATURES_SIZE 1
#define CSR_CAPABILITY_PCIE_CONFIG_ADDR 0x6808L
#define CSR_CAPABILITY_PCIE_CONFIG_SIZE 1
#define CSR_CAPABILITY_ETH_CONFIG_ADDR 0x680cL
#define CSR_CAPABILITY_ETH_CONFIG_SIZE 1
#define CSR_CAPABILITY_SATA_CONFIG_ADDR 0x6810L
#define CSR_CAPABILITY_SATA_CONFIG_SIZE 1

/* CAPABILITY Fields */
#define CSR_CAPABILITY_FEATURES_PCIE_OFFSET 0
#define CSR_CAPABILITY_FEATURES_PCIE_SIZE 1
#define CSR_CAPABILITY_FEATURES_ETH_OFFSET 1
#define CSR_CAPABILITY_FEATURES_ETH_SIZE 1
#define CSR_CAPABILITY_FEATURES_SATA_OFFSET 2
#define CSR_CAPABILITY_FEATURES_SATA_SIZE 1
#define CSR_CAPABILITY_FEATURES_GPIO_OFFSET 3
#define CSR_CAPABILITY_FEATURES_GPIO_SIZE 1
#define CSR_CAPABILITY_PCIE_CONFIG_SPEED_OFFSET 0
#define CSR_CAPABILITY_PCIE_CONFIG_SPEED_SIZE 2
#define CSR_CAPABILITY_PCIE_CONFIG_LANES_OFFSET 2
#define CSR_CAPABILITY_PCIE_CONFIG_LANES_SIZE 2
#define CSR_CAPABILITY_ETH_CONFIG_SPEED_OFFSET 0
#define CSR_CAPABILITY_ETH_CONFIG_SPEED_SIZE 2
#define CSR_CAPABILITY_SATA_CONFIG_GEN_OFFSET 0
#define CSR_CAPABILITY_SATA_CONFIG_GEN_SIZE 2

/* ETH_PHY Registers */
#define CSR_ETH_PHY_BASE 0x7000L
#define CSR_ETH_PHY_RESET_ADDR 0x7000L
#define CSR_ETH_PHY_RESET_SIZE 1

/* ETH_PHY Fields */

/* ETH_RX_STREAMER Registers */
#define CSR_ETH_RX_STREAMER_BASE 0x7800L
#define CSR_ETH_RX_STREAMER_ENABLE_ADDR 0x7800L
#define CSR_ETH_RX_STREAMER_ENABLE_SIZE 1
#define CSR_ETH_RX_STREAMER_IP_ADDRESS_ADDR 0x7804L
#define CSR_ETH_RX_STREAMER_IP_ADDRESS_SIZE 1
#define CSR_ETH_RX_STREAMER_UDP_PORT_ADDR 0x7808L
#define CSR_ETH_RX_STREAMER_UDP_PORT_SIZE 1

/* ETH_RX_STREAMER Fields */

/* ETH_TX_STREAMER Registers */
#define CSR_ETH_TX_STREAMER_BASE 0x8000L
#define CSR_ETH_TX_STREAMER_ENABLE_ADDR 0x8000L
#define CSR_ETH_TX_STREAMER_ENABLE_SIZE 1
#define CSR_ETH_TX_STREAMER_IP_ADDRESS_ADDR 0x8004L
#define CSR_ETH_TX_STREAMER_IP_ADDRESS_SIZE 1
#define CSR_ETH_TX_STREAMER_UDP_PORT_ADDR 0x8008L
#define CSR_ETH_TX_STREAMER_UDP_PORT_SIZE 1

/* ETH_TX_STREAMER Fields */

/* TIME_GEN Registers */
#define CSR_TIME_GEN_BASE 0x8800L
#define CSR_TIME_GEN_CONTROL_ADDR 0x8800L
#define CSR_TIME_GEN_CONTROL_SIZE 1
#define CSR_TIME_GEN_READ_TIME_ADDR 0x8804L
#define CSR_TIME_GEN_READ_TIME_SIZE 2
#define CSR_TIME_GEN_WRITE_TIME_ADDR 0x880cL
#define CSR_TIME_GEN_WRITE_TIME_SIZE 2
#define CSR_TIME_GEN_TIME_ADJUSTMENT_ADDR 0x8814L
#define CSR_TIME_GEN_TIME_ADJUSTMENT_SIZE 2

/* TIME_GEN Fields */
#define CSR_TIME_GEN_CONTROL_ENABLE_OFFSET 0
#define CSR_TIME_GEN_CONTROL_ENABLE_SIZE 1
#define CSR_TIME_GEN_CONTROL_READ_OFFSET 1
#define CSR_TIME_GEN_CONTROL_READ_SIZE 1
#define CSR_TIME_GEN_CONTROL_WRITE_OFFSET 2
#define CSR_TIME_GEN_CONTROL_WRITE_SIZE 1

/* SI5351 Registers */
#define CSR_SI5351_BASE 0xa000L
#define CSR_SI5351_I2C_W_ADDR 0xa000L
#define CSR_SI5351_I2C_W_SIZE 1
#define CSR_SI5351_I2C_R_ADDR 0xa004L
#define CSR_SI5351_I2C_R_SIZE 1
#define CSR_SI5351_PWM_ENABLE_ADDR 0xa008L
#define CSR_SI5351_PWM_ENABLE_SIZE 1
#define CSR_SI5351_PWM_WIDTH_ADDR 0xa00cL
#define CSR_SI5351_PWM_WIDTH_SIZE 1
#define CSR_SI5351_PWM_PERIOD_ADDR 0xa010L
#define CSR_SI5351_PWM_PERIOD_SIZE 1
#define CSR_SI5351_CONTROL_ADDR 0xa014L
#define CSR_SI5351_CONTROL_SIZE 1

/* SI5351 Fields */
#define CSR_SI5351_I2C_W_SCL_OFFSET 0
#define CSR_SI5351_I2C_W_SCL_SIZE 1
#define CSR_SI5351_I2C_W_OE_OFFSET 1
#define CSR_SI5351_I2C_W_OE_SIZE 1
#define CSR_SI5351_I2C_W_SDA_OFFSET 2
#define CSR_SI5351_I2C_W_SDA_SIZE 1
#define CSR_SI5351_I2C_R_SDA_OFFSET 0
#define CSR_SI5351_I2C_R_SDA_SIZE 1
#define CSR_SI5351_CONTROL_VERSION_OFFSET 0
#define CSR_SI5351_CONTROL_VERSION_SIZE 1
#define CSR_SI5351_CONTROL_CLK_IN_SRC_OFFSET 1
#define CSR_SI5351_CONTROL_CLK_IN_SRC_SIZE 1

/* GPIO Registers */
#define CSR_GPIO_BASE 0xa800L
#define CSR_GPIO_CONTROL_ADDR 0xa800L
#define CSR_GPIO_CONTROL_SIZE 1
#define CSR_GPIO__O_ADDR 0xa804L
#define CSR_GPIO__O_SIZE 1
#define CSR_GPIO_OE_ADDR 0xa808L
#define CSR_GPIO_OE_SIZE 1
#define CSR_GPIO__I_ADDR 0xa80cL
#define CSR_GPIO__I_SIZE 1

/* GPIO Fields */
#define CSR_GPIO_CONTROL_ENABLE_OFFSET 0
#define CSR_GPIO_CONTROL_ENABLE_SIZE 1
#define CSR_GPIO_CONTROL_SOURCE_OFFSET 1
#define CSR_GPIO_CONTROL_SOURCE_SIZE 1
#define CSR_GPIO_CONTROL_LOOPBACK_OFFSET 2
#define CSR_GPIO_CONTROL_LOOPBACK_SIZE 1
#define CSR_GPIO__O_DATA_OFFSET 0
#define CSR_GPIO__O_DATA_SIZE 4
#define CSR_GPIO_OE_ENABLE_OFFSET 0
#define CSR_GPIO_OE_ENABLE_SIZE 4
#define CSR_GPIO__I_DATA_OFFSET 0
#define CSR_GPIO__I_DATA_SIZE 4

/* PCIE_ENDPOINT Registers */
#define CSR_PCIE_ENDPOINT_BASE 0xb000L
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_ADDR 0xb000L
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_MSI_ENABLE_ADDR 0xb004L
#define CSR_PCIE_ENDPOINT_PHY_MSI_ENABLE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_MSIX_ENABLE_ADDR 0xb008L
#define CSR_PCIE_ENDPOINT_PHY_MSIX_ENABLE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_BUS_MASTER_ENABLE_ADDR 0xb00cL
#define CSR_PCIE_ENDPOINT_PHY_BUS_MASTER_ENABLE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_MAX_REQUEST_SIZE_ADDR 0xb010L
#define CSR_PCIE_ENDPOINT_PHY_MAX_REQUEST_SIZE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_MAX_PAYLOAD_SIZE_ADDR 0xb014L
#define CSR_PCIE_ENDPOINT_PHY_MAX_PAYLOAD_SIZE_SIZE 1

/* PCIE_ENDPOINT Fields */
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_STATUS_OFFSET 0
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_STATUS_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_RATE_OFFSET 1
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_RATE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_WIDTH_OFFSET 2
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_WIDTH_SIZE 2
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_LTSSM_OFFSET 4
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_LTSSM_SIZE 6

/* HEADER Registers */
#define CSR_HEADER_BASE 0xb800L
#define CSR_HEADER_TX_CONTROL_ADDR 0xb800L
#define CSR_HEADER_TX_CONTROL_SIZE 1
#define CSR_HEADER_TX_FRAME_CYCLES_ADDR 0xb804L
#define CSR_HEADER_TX_FRAME_CYCLES_SIZE 1
#define CSR_HEADER_RX_CONTROL_ADDR 0xb808L
#define CSR_HEADER_RX_CONTROL_SIZE 1
#define CSR_HEADER_RX_FRAME_CYCLES_ADDR 0xb80cL
#define CSR_HEADER_RX_FRAME_CYCLES_SIZE 1
#define CSR_HEADER_LAST_TX_HEADER_ADDR 0xb810L
#define CSR_HEADER_LAST_TX_HEADER_SIZE 2
#define CSR_HEADER_LAST_TX_TIMESTAMP_ADDR 0xb818L
#define CSR_HEADER_LAST_TX_TIMESTAMP_SIZE 2
#define CSR_HEADER_LAST_RX_HEADER_ADDR 0xb820L
#define CSR_HEADER_LAST_RX_HEADER_SIZE 2
#define CSR_HEADER_LAST_RX_TIMESTAMP_ADDR 0xb828L
#define CSR_HEADER_LAST_RX_TIMESTAMP_SIZE 2

/* HEADER Fields */
#define CSR_HEADER_TX_CONTROL_ENABLE_OFFSET 0
#define CSR_HEADER_TX_CONTROL_ENABLE_SIZE 1
#define CSR_HEADER_TX_CONTROL_HEADER_ENABLE_OFFSET 1
#define CSR_HEADER_TX_CONTROL_HEADER_ENABLE_SIZE 1
#define CSR_HEADER_RX_CONTROL_ENABLE_OFFSET 0
#define CSR_HEADER_RX_CONTROL_ENABLE_SIZE 1
#define CSR_HEADER_RX_CONTROL_HEADER_ENABLE_OFFSET 1
#define CSR_HEADER_RX_CONTROL_HEADER_ENABLE_SIZE 1

/* AD9361 Registers */
#define CSR_AD9361_BASE 0xc000L
#define CSR_AD9361_CONFIG_ADDR 0xc000L
#define CSR_AD9361_CONFIG_SIZE 1
#define CSR_AD9361_CTRL_ADDR 0xc004L
#define CSR_AD9361_CTRL_SIZE 1
#define CSR_AD9361_STAT_ADDR 0xc008L
#define CSR_AD9361_STAT_SIZE 1
#define CSR_AD9361_BITMODE_ADDR 0xc00cL
#define CSR_AD9361_BITMODE_SIZE 1
#define CSR_AD9361_SPI_CONTROL_ADDR 0xc010L
#define CSR_AD9361_SPI_CONTROL_SIZE 1
#define CSR_AD9361_SPI_STATUS_ADDR 0xc014L
#define CSR_AD9361_SPI_STATUS_SIZE 1
#define CSR_AD9361_SPI_MOSI_ADDR 0xc018L
#define CSR_AD9361_SPI_MOSI_SIZE 1
#define CSR_AD9361_SPI_MISO_ADDR 0xc01cL
#define CSR_AD9361_SPI_MISO_SIZE 1
#define CSR_AD9361_PHY_CONTROL_ADDR 0xc020L
#define CSR_AD9361_PHY_CONTROL_SIZE 1
#define CSR_AD9361_PRBS_TX_ADDR 0xc024L
#define CSR_AD9361_PRBS_TX_SIZE 1
#define CSR_AD9361_PRBS_RX_ADDR 0xc028L
#define CSR_AD9361_PRBS_RX_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX1_LOW_CONTROL_ADDR 0xc02cL
#define CSR_AD9361_AGC_COUNT_RX1_LOW_CONTROL_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX1_LOW_STATUS_ADDR 0xc030L
#define CSR_AD9361_AGC_COUNT_RX1_LOW_STATUS_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_CONTROL_ADDR 0xc034L
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_CONTROL_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_STATUS_ADDR 0xc038L
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_STATUS_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX2_LOW_CONTROL_ADDR 0xc03cL
#define CSR_AD9361_AGC_COUNT_RX2_LOW_CONTROL_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX2_LOW_STATUS_ADDR 0xc040L
#define CSR_AD9361_AGC_COUNT_RX2_LOW_STATUS_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_CONTROL_ADDR 0xc044L
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_CONTROL_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_STATUS_ADDR 0xc048L
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_STATUS_SIZE 1

/* AD9361 Fields */
#define CSR_AD9361_CONFIG_RST_N_OFFSET 0
#define CSR_AD9361_CONFIG_RST_N_SIZE 1
#define CSR_AD9361_CONFIG_ENABLE_OFFSET 1
#define CSR_AD9361_CONFIG_ENABLE_SIZE 1
#define CSR_AD9361_CONFIG_TXNRX_OFFSET 4
#define CSR_AD9361_CONFIG_TXNRX_SIZE 1
#define CSR_AD9361_CONFIG_EN_AGC_OFFSET 5
#define CSR_AD9361_CONFIG_EN_AGC_SIZE 1
#define CSR_AD9361_CTRL_CTRL_OFFSET 0
#define CSR_AD9361_CTRL_CTRL_SIZE 4
#define CSR_AD9361_STAT_STAT_OFFSET 0
#define CSR_AD9361_STAT_STAT_SIZE 8
#define CSR_AD9361_BITMODE_MODE_OFFSET 0
#define CSR_AD9361_BITMODE_MODE_SIZE 1
#define CSR_AD9361_SPI_CONTROL_START_OFFSET 0
#define CSR_AD9361_SPI_CONTROL_START_SIZE 1
#define CSR_AD9361_SPI_CONTROL_LENGTH_OFFSET 8
#define CSR_AD9361_SPI_CONTROL_LENGTH_SIZE 8
#define CSR_AD9361_SPI_STATUS_DONE_OFFSET 0
#define CSR_AD9361_SPI_STATUS_DONE_SIZE 1
#define CSR_AD9361_PHY_CONTROL_MODE_OFFSET 0
#define CSR_AD9361_PHY_CONTROL_MODE_SIZE 1
#define CSR_AD9361_PHY_CONTROL_LOOPBACK_OFFSET 1
#define CSR_AD9361_PHY_CONTROL_LOOPBACK_SIZE 1
#define CSR_AD9361_PRBS_TX_ENABLE_OFFSET 0
#define CSR_AD9361_PRBS_TX_ENABLE_SIZE 1
#define CSR_AD9361_PRBS_RX_SYNCED_OFFSET 0
#define CSR_AD9361_PRBS_RX_SYNCED_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX1_LOW_CONTROL_ENABLE_OFFSET 0
#define CSR_AD9361_AGC_COUNT_RX1_LOW_CONTROL_ENABLE_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX1_LOW_CONTROL_CLEAR_OFFSET 1
#define CSR_AD9361_AGC_COUNT_RX1_LOW_CONTROL_CLEAR_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX1_LOW_CONTROL_THRESHOLD_OFFSET 16
#define CSR_AD9361_AGC_COUNT_RX1_LOW_CONTROL_THRESHOLD_SIZE 16
#define CSR_AD9361_AGC_COUNT_RX1_LOW_STATUS_COUNT_OFFSET 0
#define CSR_AD9361_AGC_COUNT_RX1_LOW_STATUS_COUNT_SIZE 32
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_CONTROL_ENABLE_OFFSET 0
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_CONTROL_ENABLE_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_CONTROL_CLEAR_OFFSET 1
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_CONTROL_CLEAR_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_CONTROL_THRESHOLD_OFFSET 16
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_CONTROL_THRESHOLD_SIZE 16
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_STATUS_COUNT_OFFSET 0
#define CSR_AD9361_AGC_COUNT_RX1_HIGH_STATUS_COUNT_SIZE 32
#define CSR_AD9361_AGC_COUNT_RX2_LOW_CONTROL_ENABLE_OFFSET 0
#define CSR_AD9361_AGC_COUNT_RX2_LOW_CONTROL_ENABLE_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX2_LOW_CONTROL_CLEAR_OFFSET 1
#define CSR_AD9361_AGC_COUNT_RX2_LOW_CONTROL_CLEAR_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX2_LOW_CONTROL_THRESHOLD_OFFSET 16
#define CSR_AD9361_AGC_COUNT_RX2_LOW_CONTROL_THRESHOLD_SIZE 16
#define CSR_AD9361_AGC_COUNT_RX2_LOW_STATUS_COUNT_OFFSET 0
#define CSR_AD9361_AGC_COUNT_RX2_LOW_STATUS_COUNT_SIZE 32
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_CONTROL_ENABLE_OFFSET 0
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_CONTROL_ENABLE_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_CONTROL_CLEAR_OFFSET 1
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_CONTROL_CLEAR_SIZE 1
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_CONTROL_THRESHOLD_OFFSET 16
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_CONTROL_THRESHOLD_SIZE 16
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_STATUS_COUNT_OFFSET 0
#define CSR_AD9361_AGC_COUNT_RX2_HIGH_STATUS_COUNT_SIZE 32

/* CROSSBAR Registers */
#define CSR_CROSSBAR_BASE 0xc800L
#define CSR_CROSSBAR_MUX_SEL_ADDR 0xc800L
#define CSR_CROSSBAR_MUX_SEL_SIZE 1
#define CSR_CROSSBAR_DEMUX_SEL_ADDR 0xc804L
#define CSR_CROSSBAR_DEMUX_SEL_SIZE 1

/* CROSSBAR Fields */

/* CLK_MEASUREMENT Registers */
#define CSR_CLK_MEASUREMENT_BASE 0xf000L
#define CSR_CLK_MEASUREMENT_CLK0_LATCH_ADDR 0xf000L
#define CSR_CLK_MEASUREMENT_CLK0_LATCH_SIZE 1
#define CSR_CLK_MEASUREMENT_CLK0_VALUE_ADDR 0xf004L
#define CSR_CLK_MEASUREMENT_CLK0_VALUE_SIZE 2
#define CSR_CLK_MEASUREMENT_CLK1_LATCH_ADDR 0xf00cL
#define CSR_CLK_MEASUREMENT_CLK1_LATCH_SIZE 1
#define CSR_CLK_MEASUREMENT_CLK1_VALUE_ADDR 0xf010L
#define CSR_CLK_MEASUREMENT_CLK1_VALUE_SIZE 2
#define CSR_CLK_MEASUREMENT_CLK2_LATCH_ADDR 0xf018L
#define CSR_CLK_MEASUREMENT_CLK2_LATCH_SIZE 1
#define CSR_CLK_MEASUREMENT_CLK2_VALUE_ADDR 0xf01cL
#define CSR_CLK_MEASUREMENT_CLK2_VALUE_SIZE 2
#define CSR_CLK_MEASUREMENT_CLK3_LATCH_ADDR 0xf024L
#define CSR_CLK_MEASUREMENT_CLK3_LATCH_SIZE 1
#define CSR_CLK_MEASUREMENT_CLK3_VALUE_ADDR 0xf028L
#define CSR_CLK_MEASUREMENT_CLK3_VALUE_SIZE 2
#define CSR_CLK_MEASUREMENT_CLK4_LATCH_ADDR 0xf030L
#define CSR_CLK_MEASUREMENT_CLK4_LATCH_SIZE 1
#define CSR_CLK_MEASUREMENT_CLK4_VALUE_ADDR 0xf034L
#define CSR_CLK_MEASUREMENT_CLK4_VALUE_SIZE 2
#define CSR_CLK_MEASUREMENT_LATCH_ALL_ADDR 0xf03cL
#define CSR_CLK_MEASUREMENT_LATCH_ALL_SIZE 1

/* CLK_MEASUREMENT Fields */

#endif /* ! __GENERATED_CSR_H */
