//Copyright (C)2014-2023 Gowin Semiconductor Corporation.
//All rights reserved.
//File Title: Template file for instantiation
//GOWIN Version: V1.9.9 Beta-6
//Part Number: GW5AST-LV138FPG676AES
//Device: GW5AST-138
//Device Version: B
//Created Time: Wed Nov 01 09:23:23 2023

//Change the instance name and port connections to the signal names
//--------Copy here to design--------

	RiscV_AE350_SOC_Top your_instance_name(
		.FLASH_SPI_CSN(FLASH_SPI_CSN_io), //inout FLASH_SPI_CSN
		.FLASH_SPI_MISO(FLASH_SPI_MISO_io), //inout FLASH_SPI_MISO
		.FLASH_SPI_MOSI(FLASH_SPI_MOSI_io), //inout FLASH_SPI_MOSI
		.FLASH_SPI_CLK(FLASH_SPI_CLK_io), //inout FLASH_SPI_CLK
		.FLASH_SPI_HOLDN(FLASH_SPI_HOLDN_io), //inout FLASH_SPI_HOLDN
		.FLASH_SPI_WPN(FLASH_SPI_WPN_io), //inout FLASH_SPI_WPN
		.DDR3_MEMORY_CLK(DDR3_MEMORY_CLK_i), //input DDR3_MEMORY_CLK
		.DDR3_CLK_IN(DDR3_CLK_IN_i), //input DDR3_CLK_IN
		.DDR3_RSTN(DDR3_RSTN_i), //input DDR3_RSTN
		.DDR3_LOCK(DDR3_LOCK_i), //input DDR3_LOCK
		.DDR3_STOP(DDR3_STOP_o), //output DDR3_STOP
		.DDR3_INIT(DDR3_INIT_o), //output DDR3_INIT
		.DDR3_BANK(DDR3_BANK_o), //output [2:0] DDR3_BANK
		.DDR3_CS_N(DDR3_CS_N_o), //output DDR3_CS_N
		.DDR3_RAS_N(DDR3_RAS_N_o), //output DDR3_RAS_N
		.DDR3_CAS_N(DDR3_CAS_N_o), //output DDR3_CAS_N
		.DDR3_WE_N(DDR3_WE_N_o), //output DDR3_WE_N
		.DDR3_CK(DDR3_CK_o), //output DDR3_CK
		.DDR3_CK_N(DDR3_CK_N_o), //output DDR3_CK_N
		.DDR3_CKE(DDR3_CKE_o), //output DDR3_CKE
		.DDR3_RESET_N(DDR3_RESET_N_o), //output DDR3_RESET_N
		.DDR3_ODT(DDR3_ODT_o), //output DDR3_ODT
		.DDR3_ADDR(DDR3_ADDR_o), //output [13:0] DDR3_ADDR
		.DDR3_DM(DDR3_DM_o), //output [1:0] DDR3_DM
		.DDR3_DQ(DDR3_DQ_io), //inout [15:0] DDR3_DQ
		.DDR3_DQS(DDR3_DQS_io), //inout [1:0] DDR3_DQS
		.DDR3_DQS_N(DDR3_DQS_N_io), //inout [1:0] DDR3_DQS_N
		.TCK_IN(TCK_IN_i), //input TCK_IN
		.TMS_IN(TMS_IN_i), //input TMS_IN
		.TRST_IN(TRST_IN_i), //input TRST_IN
		.TDI_IN(TDI_IN_i), //input TDI_IN
		.TDO_OUT(TDO_OUT_o), //output TDO_OUT
		.TDO_OE(TDO_OE_o), //output TDO_OE
		.EXT_INT(EXT_INT_i), //input [15:0] EXT_INT
		.EXTS_HRDATA(EXTS_HRDATA_i), //input [31:0] EXTS_HRDATA
		.EXTS_HREADYIN(EXTS_HREADYIN_i), //input EXTS_HREADYIN
		.EXTS_HRESP(EXTS_HRESP_i), //input EXTS_HRESP
		.EXTS_HADDR(EXTS_HADDR_o), //output [31:0] EXTS_HADDR
		.EXTS_HBURST(EXTS_HBURST_o), //output [2:0] EXTS_HBURST
		.EXTS_HPROT(EXTS_HPROT_o), //output [3:0] EXTS_HPROT
		.EXTS_HSEL(EXTS_HSEL_o), //output EXTS_HSEL
		.EXTS_HSIZE(EXTS_HSIZE_o), //output [2:0] EXTS_HSIZE
		.EXTS_HTRANS(EXTS_HTRANS_o), //output [1:0] EXTS_HTRANS
		.EXTS_HWDATA(EXTS_HWDATA_o), //output [31:0] EXTS_HWDATA
		.EXTS_HWRITE(EXTS_HWRITE_o), //output EXTS_HWRITE
		.EXTS_HCLK(EXTS_HCLK_o), //output EXTS_HCLK
		.EXTS_HRSTN(EXTS_HRSTN_o), //output EXTS_HRSTN
		.UART2_TXD(UART2_TXD_o), //output UART2_TXD
		.UART2_RTSN(UART2_RTSN_o), //output UART2_RTSN
		.UART2_RXD(UART2_RXD_i), //input UART2_RXD
		.UART2_CTSN(UART2_CTSN_i), //input UART2_CTSN
		.UART2_DCDN(UART2_DCDN_i), //input UART2_DCDN
		.UART2_DSRN(UART2_DSRN_i), //input UART2_DSRN
		.UART2_RIN(UART2_RIN_i), //input UART2_RIN
		.UART2_DTRN(UART2_DTRN_o), //output UART2_DTRN
		.UART2_OUT1N(UART2_OUT1N_o), //output UART2_OUT1N
		.UART2_OUT2N(UART2_OUT2N_o), //output UART2_OUT2N
		.CORE_CLK(CORE_CLK_i), //input CORE_CLK
		.DDR_CLK(DDR_CLK_i), //input DDR_CLK
		.AHB_CLK(AHB_CLK_i), //input AHB_CLK
		.APB_CLK(APB_CLK_i), //input APB_CLK
		.RTC_CLK(RTC_CLK_i), //input RTC_CLK
		.POR_RSTN(POR_RSTN_i), //input POR_RSTN
		.HW_RSTN(HW_RSTN_i) //input HW_RSTN
	);

//--------Copy end-------------------
