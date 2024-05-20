//--------------------------------------------------------------------------------
// Auto-generated by LiteX (4b3f147f) on 2024-05-20 08:52:09
//--------------------------------------------------------------------------------
#ifndef __GENERATED_CSR_H
#define __GENERATED_CSR_H

#ifndef CSR_BASE
#define CSR_BASE 0x0L
#endif

/* ad9361_spi */
#define CSR_AD9361_SPI_BASE (CSR_BASE + 0x0L)
#define CSR_AD9361_SPI_CTRL_ADDR (CSR_BASE + 0x0L)
#define CSR_AD9361_SPI_CTRL_SIZE 1
#define CSR_AD9361_SPI_STATUS_ADDR (CSR_BASE + 0x4L)
#define CSR_AD9361_SPI_STATUS_SIZE 1
#define CSR_AD9361_SPI_MOSI_ADDR (CSR_BASE + 0x8L)
#define CSR_AD9361_SPI_MOSI_SIZE 1
#define CSR_AD9361_SPI_MISO_ADDR (CSR_BASE + 0xcL)
#define CSR_AD9361_SPI_MISO_SIZE 1

/* analyzer */
#define CSR_ANALYZER_BASE (CSR_BASE + 0x800L)
#define CSR_ANALYZER_MUX_VALUE_ADDR (CSR_BASE + 0x800L)
#define CSR_ANALYZER_MUX_VALUE_SIZE 1
#define CSR_ANALYZER_TRIGGER_ENABLE_ADDR (CSR_BASE + 0x804L)
#define CSR_ANALYZER_TRIGGER_ENABLE_SIZE 1
#define CSR_ANALYZER_TRIGGER_DONE_ADDR (CSR_BASE + 0x808L)
#define CSR_ANALYZER_TRIGGER_DONE_SIZE 1
#define CSR_ANALYZER_TRIGGER_MEM_WRITE_ADDR (CSR_BASE + 0x80cL)
#define CSR_ANALYZER_TRIGGER_MEM_WRITE_SIZE 1
#define CSR_ANALYZER_TRIGGER_MEM_MASK_ADDR (CSR_BASE + 0x810L)
#define CSR_ANALYZER_TRIGGER_MEM_MASK_SIZE 1
#define CSR_ANALYZER_TRIGGER_MEM_VALUE_ADDR (CSR_BASE + 0x814L)
#define CSR_ANALYZER_TRIGGER_MEM_VALUE_SIZE 1
#define CSR_ANALYZER_TRIGGER_MEM_FULL_ADDR (CSR_BASE + 0x818L)
#define CSR_ANALYZER_TRIGGER_MEM_FULL_SIZE 1
#define CSR_ANALYZER_SUBSAMPLER_VALUE_ADDR (CSR_BASE + 0x81cL)
#define CSR_ANALYZER_SUBSAMPLER_VALUE_SIZE 1
#define CSR_ANALYZER_STORAGE_ENABLE_ADDR (CSR_BASE + 0x820L)
#define CSR_ANALYZER_STORAGE_ENABLE_SIZE 1
#define CSR_ANALYZER_STORAGE_DONE_ADDR (CSR_BASE + 0x824L)
#define CSR_ANALYZER_STORAGE_DONE_SIZE 1
#define CSR_ANALYZER_STORAGE_LENGTH_ADDR (CSR_BASE + 0x828L)
#define CSR_ANALYZER_STORAGE_LENGTH_SIZE 1
#define CSR_ANALYZER_STORAGE_OFFSET_ADDR (CSR_BASE + 0x82cL)
#define CSR_ANALYZER_STORAGE_OFFSET_SIZE 1
#define CSR_ANALYZER_STORAGE_MEM_LEVEL_ADDR (CSR_BASE + 0x830L)
#define CSR_ANALYZER_STORAGE_MEM_LEVEL_SIZE 1
#define CSR_ANALYZER_STORAGE_MEM_DATA_ADDR (CSR_BASE + 0x834L)
#define CSR_ANALYZER_STORAGE_MEM_DATA_SIZE 1

/* ctrl */
#define CSR_CTRL_BASE (CSR_BASE + 0x1000L)
#define CSR_CTRL_RESET_ADDR (CSR_BASE + 0x1000L)
#define CSR_CTRL_RESET_SIZE 1
#define CSR_CTRL_RESET_SOC_RST_OFFSET 0
#define CSR_CTRL_RESET_SOC_RST_SIZE 1
#define CSR_CTRL_RESET_CPU_RST_OFFSET 1
#define CSR_CTRL_RESET_CPU_RST_SIZE 1
#define CSR_CTRL_SCRATCH_ADDR (CSR_BASE + 0x1004L)
#define CSR_CTRL_SCRATCH_SIZE 1
#define CSR_CTRL_BUS_ERRORS_ADDR (CSR_BASE + 0x1008L)
#define CSR_CTRL_BUS_ERRORS_SIZE 1

/* dna */
#define CSR_DNA_BASE (CSR_BASE + 0x1800L)
#define CSR_DNA_ID_ADDR (CSR_BASE + 0x1800L)
#define CSR_DNA_ID_SIZE 2

/* icap */
#define CSR_ICAP_BASE (CSR_BASE + 0x2000L)
#define CSR_ICAP_ADDR_ADDR (CSR_BASE + 0x2000L)
#define CSR_ICAP_ADDR_SIZE 1
#define CSR_ICAP_DATA_ADDR (CSR_BASE + 0x2004L)
#define CSR_ICAP_DATA_SIZE 1
#define CSR_ICAP_WRITE_ADDR (CSR_BASE + 0x2008L)
#define CSR_ICAP_WRITE_SIZE 1
#define CSR_ICAP_DONE_ADDR (CSR_BASE + 0x200cL)
#define CSR_ICAP_DONE_SIZE 1
#define CSR_ICAP_READ_ADDR (CSR_BASE + 0x2010L)
#define CSR_ICAP_READ_SIZE 1

/* identifier_mem */
#define CSR_IDENTIFIER_MEM_BASE (CSR_BASE + 0x2800L)

/* leds */
#define CSR_LEDS_BASE (CSR_BASE + 0x3000L)
#define CSR_LEDS_OUT_ADDR (CSR_BASE + 0x3000L)
#define CSR_LEDS_OUT_SIZE 1

/* main */
#define CSR_MAIN_BASE (CSR_BASE + 0x3800L)
#define CSR_MAIN_AD9361_ENABLE_ADDR (CSR_BASE + 0x3800L)
#define CSR_MAIN_AD9361_ENABLE_SIZE 1

/* pcie_dma0 */
#define CSR_PCIE_DMA0_BASE (CSR_BASE + 0x4000L)
#define CSR_PCIE_DMA0_WRITER_ENABLE_ADDR (CSR_BASE + 0x4000L)
#define CSR_PCIE_DMA0_WRITER_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDR (CSR_BASE + 0x4004L)
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_SIZE 2
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDRESS_LSB_OFFSET 0
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_ADDRESS_LSB_SIZE 32
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LENGTH_OFFSET 32
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LENGTH_SIZE 24
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_IRQ_DISABLE_OFFSET 56
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_IRQ_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LAST_DISABLE_OFFSET 57
#define CSR_PCIE_DMA0_WRITER_TABLE_VALUE_LAST_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_ADDR (CSR_BASE + 0x400cL)
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_ADDRESS_MSB_OFFSET 0
#define CSR_PCIE_DMA0_WRITER_TABLE_WE_ADDRESS_MSB_SIZE 32
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_PROG_N_ADDR (CSR_BASE + 0x4010L)
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_PROG_N_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_ADDR (CSR_BASE + 0x4014L)
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_INDEX_OFFSET 0
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_INDEX_SIZE 16
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_COUNT_OFFSET 16
#define CSR_PCIE_DMA0_WRITER_TABLE_LOOP_STATUS_COUNT_SIZE 16
#define CSR_PCIE_DMA0_WRITER_TABLE_LEVEL_ADDR (CSR_BASE + 0x4018L)
#define CSR_PCIE_DMA0_WRITER_TABLE_LEVEL_SIZE 1
#define CSR_PCIE_DMA0_WRITER_TABLE_RESET_ADDR (CSR_BASE + 0x401cL)
#define CSR_PCIE_DMA0_WRITER_TABLE_RESET_SIZE 1
#define CSR_PCIE_DMA0_READER_ENABLE_ADDR (CSR_BASE + 0x4020L)
#define CSR_PCIE_DMA0_READER_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDR (CSR_BASE + 0x4024L)
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_SIZE 2
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDRESS_LSB_OFFSET 0
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_ADDRESS_LSB_SIZE 32
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LENGTH_OFFSET 32
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LENGTH_SIZE 24
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_IRQ_DISABLE_OFFSET 56
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_IRQ_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LAST_DISABLE_OFFSET 57
#define CSR_PCIE_DMA0_READER_TABLE_VALUE_LAST_DISABLE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_WE_ADDR (CSR_BASE + 0x402cL)
#define CSR_PCIE_DMA0_READER_TABLE_WE_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_WE_ADDRESS_MSB_OFFSET 0
#define CSR_PCIE_DMA0_READER_TABLE_WE_ADDRESS_MSB_SIZE 32
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_PROG_N_ADDR (CSR_BASE + 0x4030L)
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_PROG_N_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_ADDR (CSR_BASE + 0x4034L)
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_INDEX_OFFSET 0
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_INDEX_SIZE 16
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_COUNT_OFFSET 16
#define CSR_PCIE_DMA0_READER_TABLE_LOOP_STATUS_COUNT_SIZE 16
#define CSR_PCIE_DMA0_READER_TABLE_LEVEL_ADDR (CSR_BASE + 0x4038L)
#define CSR_PCIE_DMA0_READER_TABLE_LEVEL_SIZE 1
#define CSR_PCIE_DMA0_READER_TABLE_RESET_ADDR (CSR_BASE + 0x403cL)
#define CSR_PCIE_DMA0_READER_TABLE_RESET_SIZE 1
#define CSR_PCIE_DMA0_LOOPBACK_ENABLE_ADDR (CSR_BASE + 0x4040L)
#define CSR_PCIE_DMA0_LOOPBACK_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_SYNCHRONIZER_BYPASS_ADDR (CSR_BASE + 0x4044L)
#define CSR_PCIE_DMA0_SYNCHRONIZER_BYPASS_SIZE 1
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_ADDR (CSR_BASE + 0x4048L)
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_SIZE 1
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_MODE_OFFSET 0
#define CSR_PCIE_DMA0_SYNCHRONIZER_ENABLE_MODE_SIZE 2
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_ADDR (CSR_BASE + 0x404cL)
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_DEPTH_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_DEPTH_SIZE 24
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_SCRATCH_OFFSET 24
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_SCRATCH_SIZE 4
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_LEVEL_MODE_OFFSET 31
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_CONTROL_LEVEL_MODE_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_ADDR (CSR_BASE + 0x4050L)
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_LEVEL_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_READER_FIFO_STATUS_LEVEL_SIZE 24
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_ADDR (CSR_BASE + 0x4054L)
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_DEPTH_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_DEPTH_SIZE 24
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_SCRATCH_OFFSET 24
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_SCRATCH_SIZE 4
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_LEVEL_MODE_OFFSET 31
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_CONTROL_LEVEL_MODE_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_ADDR (CSR_BASE + 0x4058L)
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_SIZE 1
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_LEVEL_OFFSET 0
#define CSR_PCIE_DMA0_BUFFERING_WRITER_FIFO_STATUS_LEVEL_SIZE 24

/* pcie_endpoint */
#define CSR_PCIE_ENDPOINT_BASE (CSR_BASE + 0x4800L)
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_ADDR (CSR_BASE + 0x4800L)
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_STATUS_OFFSET 0
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_STATUS_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_RATE_OFFSET 1
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_RATE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_WIDTH_OFFSET 2
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_WIDTH_SIZE 2
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_LTSSM_OFFSET 4
#define CSR_PCIE_ENDPOINT_PHY_LINK_STATUS_LTSSM_SIZE 6
#define CSR_PCIE_ENDPOINT_PHY_MSI_ENABLE_ADDR (CSR_BASE + 0x4804L)
#define CSR_PCIE_ENDPOINT_PHY_MSI_ENABLE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_MSIX_ENABLE_ADDR (CSR_BASE + 0x4808L)
#define CSR_PCIE_ENDPOINT_PHY_MSIX_ENABLE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_BUS_MASTER_ENABLE_ADDR (CSR_BASE + 0x480cL)
#define CSR_PCIE_ENDPOINT_PHY_BUS_MASTER_ENABLE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_MAX_REQUEST_SIZE_ADDR (CSR_BASE + 0x4810L)
#define CSR_PCIE_ENDPOINT_PHY_MAX_REQUEST_SIZE_SIZE 1
#define CSR_PCIE_ENDPOINT_PHY_MAX_PAYLOAD_SIZE_ADDR (CSR_BASE + 0x4814L)
#define CSR_PCIE_ENDPOINT_PHY_MAX_PAYLOAD_SIZE_SIZE 1

/* pcie_msi */
#define CSR_PCIE_MSI_BASE (CSR_BASE + 0x5000L)
#define CSR_PCIE_MSI_ENABLE_ADDR (CSR_BASE + 0x5000L)
#define CSR_PCIE_MSI_ENABLE_SIZE 1
#define CSR_PCIE_MSI_CLEAR_ADDR (CSR_BASE + 0x5004L)
#define CSR_PCIE_MSI_CLEAR_SIZE 1
#define CSR_PCIE_MSI_VECTOR_ADDR (CSR_BASE + 0x5008L)
#define CSR_PCIE_MSI_VECTOR_SIZE 1

/* pcie_phy */
#define CSR_PCIE_PHY_BASE (CSR_BASE + 0x5800L)
#define CSR_PCIE_PHY_PHY_LINK_STATUS_ADDR (CSR_BASE + 0x5800L)
#define CSR_PCIE_PHY_PHY_LINK_STATUS_SIZE 1
#define CSR_PCIE_PHY_PHY_LINK_STATUS_STATUS_OFFSET 0
#define CSR_PCIE_PHY_PHY_LINK_STATUS_STATUS_SIZE 1
#define CSR_PCIE_PHY_PHY_LINK_STATUS_RATE_OFFSET 1
#define CSR_PCIE_PHY_PHY_LINK_STATUS_RATE_SIZE 1
#define CSR_PCIE_PHY_PHY_LINK_STATUS_WIDTH_OFFSET 2
#define CSR_PCIE_PHY_PHY_LINK_STATUS_WIDTH_SIZE 2
#define CSR_PCIE_PHY_PHY_LINK_STATUS_LTSSM_OFFSET 4
#define CSR_PCIE_PHY_PHY_LINK_STATUS_LTSSM_SIZE 6
#define CSR_PCIE_PHY_PHY_MSI_ENABLE_ADDR (CSR_BASE + 0x5804L)
#define CSR_PCIE_PHY_PHY_MSI_ENABLE_SIZE 1
#define CSR_PCIE_PHY_PHY_MSIX_ENABLE_ADDR (CSR_BASE + 0x5808L)
#define CSR_PCIE_PHY_PHY_MSIX_ENABLE_SIZE 1
#define CSR_PCIE_PHY_PHY_BUS_MASTER_ENABLE_ADDR (CSR_BASE + 0x580cL)
#define CSR_PCIE_PHY_PHY_BUS_MASTER_ENABLE_SIZE 1
#define CSR_PCIE_PHY_PHY_MAX_REQUEST_SIZE_ADDR (CSR_BASE + 0x5810L)
#define CSR_PCIE_PHY_PHY_MAX_REQUEST_SIZE_SIZE 1
#define CSR_PCIE_PHY_PHY_MAX_PAYLOAD_SIZE_ADDR (CSR_BASE + 0x5814L)
#define CSR_PCIE_PHY_PHY_MAX_PAYLOAD_SIZE_SIZE 1

/* si5351_clk0_measurement */
#define CSR_SI5351_CLK0_MEASUREMENT_BASE (CSR_BASE + 0x6000L)
#define CSR_SI5351_CLK0_MEASUREMENT_LATCH_ADDR (CSR_BASE + 0x6000L)
#define CSR_SI5351_CLK0_MEASUREMENT_LATCH_SIZE 1
#define CSR_SI5351_CLK0_MEASUREMENT_VALUE_ADDR (CSR_BASE + 0x6004L)
#define CSR_SI5351_CLK0_MEASUREMENT_VALUE_SIZE 2

/* si5351_clk1_measurement */
#define CSR_SI5351_CLK1_MEASUREMENT_BASE (CSR_BASE + 0x6800L)
#define CSR_SI5351_CLK1_MEASUREMENT_LATCH_ADDR (CSR_BASE + 0x6800L)
#define CSR_SI5351_CLK1_MEASUREMENT_LATCH_SIZE 1
#define CSR_SI5351_CLK1_MEASUREMENT_VALUE_ADDR (CSR_BASE + 0x6804L)
#define CSR_SI5351_CLK1_MEASUREMENT_VALUE_SIZE 2

/* si5351_clk2_measurement */
#define CSR_SI5351_CLK2_MEASUREMENT_BASE (CSR_BASE + 0x7000L)
#define CSR_SI5351_CLK2_MEASUREMENT_LATCH_ADDR (CSR_BASE + 0x7000L)
#define CSR_SI5351_CLK2_MEASUREMENT_LATCH_SIZE 1
#define CSR_SI5351_CLK2_MEASUREMENT_VALUE_ADDR (CSR_BASE + 0x7004L)
#define CSR_SI5351_CLK2_MEASUREMENT_VALUE_SIZE 2

/* si5351_clk3_measurement */
#define CSR_SI5351_CLK3_MEASUREMENT_BASE (CSR_BASE + 0x7800L)
#define CSR_SI5351_CLK3_MEASUREMENT_LATCH_ADDR (CSR_BASE + 0x7800L)
#define CSR_SI5351_CLK3_MEASUREMENT_LATCH_SIZE 1
#define CSR_SI5351_CLK3_MEASUREMENT_VALUE_ADDR (CSR_BASE + 0x7804L)
#define CSR_SI5351_CLK3_MEASUREMENT_VALUE_SIZE 2

/* si5351_i2c */
#define CSR_SI5351_I2C_BASE (CSR_BASE + 0x8000L)
#define CSR_SI5351_I2C_W_ADDR (CSR_BASE + 0x8000L)
#define CSR_SI5351_I2C_W_SIZE 1
#define CSR_SI5351_I2C_W_SCL_OFFSET 0
#define CSR_SI5351_I2C_W_SCL_SIZE 1
#define CSR_SI5351_I2C_W_OE_OFFSET 1
#define CSR_SI5351_I2C_W_OE_SIZE 1
#define CSR_SI5351_I2C_W_SDA_OFFSET 2
#define CSR_SI5351_I2C_W_SDA_SIZE 1
#define CSR_SI5351_I2C_R_ADDR (CSR_BASE + 0x8004L)
#define CSR_SI5351_I2C_R_SIZE 1
#define CSR_SI5351_I2C_R_SDA_OFFSET 0
#define CSR_SI5351_I2C_R_SDA_SIZE 1

/* si5351_pwm */
#define CSR_SI5351_PWM_BASE (CSR_BASE + 0x8800L)
#define CSR_SI5351_PWM_ENABLE_ADDR (CSR_BASE + 0x8800L)
#define CSR_SI5351_PWM_ENABLE_SIZE 1
#define CSR_SI5351_PWM_WIDTH_ADDR (CSR_BASE + 0x8804L)
#define CSR_SI5351_PWM_WIDTH_SIZE 1
#define CSR_SI5351_PWM_PERIOD_ADDR (CSR_BASE + 0x8808L)
#define CSR_SI5351_PWM_PERIOD_SIZE 1

/* xadc */
#define CSR_XADC_BASE (CSR_BASE + 0x9000L)
#define CSR_XADC_TEMPERATURE_ADDR (CSR_BASE + 0x9000L)
#define CSR_XADC_TEMPERATURE_SIZE 1
#define CSR_XADC_VCCINT_ADDR (CSR_BASE + 0x9004L)
#define CSR_XADC_VCCINT_SIZE 1
#define CSR_XADC_VCCAUX_ADDR (CSR_BASE + 0x9008L)
#define CSR_XADC_VCCAUX_SIZE 1
#define CSR_XADC_VCCBRAM_ADDR (CSR_BASE + 0x900cL)
#define CSR_XADC_VCCBRAM_SIZE 1
#define CSR_XADC_EOC_ADDR (CSR_BASE + 0x9010L)
#define CSR_XADC_EOC_SIZE 1
#define CSR_XADC_EOS_ADDR (CSR_BASE + 0x9014L)
#define CSR_XADC_EOS_SIZE 1

#endif
