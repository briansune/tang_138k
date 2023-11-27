------------------------------------------------------------------------------------------------------------------------------------------------
Extended AHB Ethernet Solution Read Me File
------------------------------------------------------------------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------------------------------------------------------------
1. Introduction
The demo is:
  Extend AHB Ethernet with Extended AHB Slave.
------------------------------------------------------------------------------------------------------------------------------------------------
2. Platform
2.1 Hardware Target
  Tang-MEGA-138K-Pro-Dock : GW5AST-LV138FPG676AES
2.2 Software Version
  Version tested:
    Gowin_V1.9.9 (64-bit)
    AE350_RDS V1.1
------------------------------------------------------------------------------------------------------------------------------------------------
3. Design
3.1 Hardware Design
  Reference design
    * solution\Extended_AHB_Ethernet\ref_design\FPGA_RefDesign\Tang_MEGA_138K_Pro_Dock\ae350_ext_ethernet
  'RiscV_AE350_SOC' configurations:
    * Frequency
      - CORE clock        : 400MHz
      - DDR clock         : 50MHz
      - AHB clock         : 50MHz
      - APB clock         : 50MHz
      - RTC clock         : 10MHz
      - DDR3 memory clock : 200MHz
      - DDR3 input clock  : 50MHz
      - GTX clock         : 125MHz
      - ETH clock         : 25MHz
    * Embedded Instruction Memory
    * Embedded Data Memory
    * PLIC
    * RTC
    * UART2
    * Extended AHB Slave
  'Triple Mode Ethernet MAC' Configurations:
    * Interface: RGMII
    * RGMII Input Delay: 190
    * MIIM Clock Divider: 20
3.2 Software Design
  Reference design
    * solution\Extended_AHB_Ethernet\ref_design\MCU_RefDesign\baremetal\ae350_ext_ethernet
    * BUILD_BURN : ae350-ddr.sag
    * Cache      : L1 I-cache and D-cache
------------------------------------------------------------------------------------------------------------------------------------------------
4. Program
  Programmer
4.1 Hardware Program
  configurations:
  * Access Mode : External Flash Mode 5AT
  * Operation : exFlash Erase, Program 5AT
  * Programming Options
    - File name : *.fs
  * External Flash Options
    - Device : Generic Flash
    - Start Address : 0x000000
4.2 Software Program
  configurations:
  * Access Mode : External Flash Mode 5AT
  * Operation : exFlash C Bin Erase, Program 5AT
  * External Flash Options
    - Device : Generic Flash
    - Start Address : 0x600000
  * FW/MCU/Binary Input Options
    - Firmware/Binary File : *.bin
------------------------------------------------------------------------------------------------------------------------------------------------
5. Software Programming
5.1 Register
  typedef struct
  {
    union
    {
      __O  unsigned int ETH_TX_DATA[384];       /* 0x000~0x5ff transmit data registers          */
      __I  unsigned int ETH_RX_DATA[384];       /* 0x000~0x5ff receive data registers           */
    };
    __IO unsigned int ETH_TX_LENGTH;            /* 0x600 transmit data length, bit[10:0]        */
    __IO unsigned int ETH_TX_EN;                /* 0x604 transmit enable, bit[0]                */
    __IO unsigned int ETH_TX_FAIL;              /* 0x608 transmit fail, bit[2,1,0]              */
    __I  unsigned int ETH_TX_IS;                /* 0x60c transmit interrupt status, bit[0]      */
    __O  unsigned int ETH_TX_IC;                /* 0x610 transmit interrupt clear, bit[0]       */
    __IO unsigned int ETH_TX_IE;                /* 0x614 transmit interrupt enable, bit[0]      */
         unsigned int RESERVED_1[26];           /* 0x618~0x67f reserved                         */
    __I  unsigned int ETH_RX_LENGTH;            /* 0x680 receive data length                    */
    __I  unsigned int ETH_RX_IS;                /* 0x684 receive interrupt status, bit[0]       */
    __IO unsigned int ETH_RX_IE;                /* 0x688 receive interrupt enable, bit[0]       */
    __O  unsigned int ETH_RX_IC;                /* 0x68c receive interrupt clear, bit[0]        */
         unsigned int RESERVED_2[28];           /* 0x690~0x6ff reserved                         */
    __IO unsigned int MIIM_OP_MODE;             /* 0x700 MIIM operation mode, bit[0]            */
    __IO unsigned int MIIM_PHY_ADDR;            /* 0x704 MIIM physical address, bit[4:0]        */
    __IO unsigned int MIIM_REG_ADDR;            /* 0x708 MIIM register address, bit[4:0]        */
    __IO unsigned int MIIM_WR_DATA;             /* 0x70c MIIM write data, bit[15:0]             */
    __I  unsigned int MIIM_RD_DATA;             /* 0x710 MIIM read data, bit[15:0]              */
    __I  unsigned int MIIM_IS;                  /* 0x714 MIIM interrupt status, bit[1,0]        */
    __IO unsigned int MIIM_IE;                  /* 0x718 MIIM interrupt enable, bit[1,0]        */
    __O  unsigned int MIIM_IC;                  /* 0x71c MIIM interrupt clear, bit[1,0]         */
    __IO unsigned int MIIM_OP_EN;               /* 0x720 MIIM operation enable, bit[0]          */
    __IO unsigned int ETH_MODE;                 /* 0x724 Ethernet operation mode, bit[2,1,0]    */
  } ETHERNET_RegDef;
5.2 Address
  AHB_EXT_BASE
5.3 interrupt
  IRQ_GP0_SOURCE
  gp0_irq_handler
5.4 Driver
  typedef struct _AE350_DRIVER_ETHERNET
  {
    int32_t (*init)             (uint8_t *rx_ptr, uint32_t *rx_data_length, uint32_t *miim_rd_ptr);       // Initializes
    int32_t (*eth_tx)           (uint8_t *tx_message, uint32_t tx_length);                                // Transmit
    void    (*miim_write)       (uint8_t miim_phy_address, uint8_t miim_reg_addr, uint16_t miim_wr_data); // MIIM write
    void    (*miim_receive)     (uint8_t miim_phy_address, uint8_t miim_reg_addr);                        // MIIM receive
    void    (*eth_set_mode)     (uint32_t eth_mode);                                                      // Set working mode
  } const AE350_DRIVER_ETHERNET;
------------------------------------------------------------------------------------------------------------------------------------------------