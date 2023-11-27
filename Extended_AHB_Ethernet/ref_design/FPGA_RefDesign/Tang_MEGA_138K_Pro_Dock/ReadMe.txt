----------------------------------------------------------------------
RiscV_AE350_SOC Solution FPGA Reference Design Read Me File
----------------------------------------------------------------------

----------------------------------------------------------------------
Extended AHB Ethernet
----------------------------------------------------------------------
Frequency
    CORE clock        : 400MHz
    DDR clock         : 50MHz
    AHB clock         : 50MHz
    APB clock         : 50MHz
    RTC clock         : 10MHz
    DDR3 memory clock : 200MHz
    DDR3 input clock  : 50MHz
    GTX clock         : 125MHz
    ETH clock         : 25MHz
----------------------------------------------------------------------
Platform
    Tang_MEGA_138K_Pro_Dock
        GW5AST-LV138FPG676AES
        GW5AST-138
        B
----------------------------------------------------------------------
Configuration
    RiscV_AE350_SOC
        Embedded Instruction Memory
        Embedded Data Memory
        PLIC
        UART2
        RTC
        Extended AHB Slave
    Triple Mode Ethernet MAC
        Interface: RGMII
        RGMII Input Delay: 190
        MIIM Clock Divider: 20
----------------------------------------------------------------------
IDE
    Version tested: Gowin_V1.9.9 (64-bit)
----------------------------------------------------------------------