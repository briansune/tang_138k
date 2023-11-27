/*
 * ******************************************************************************************
 * File		: ethernet.h
 * Author	: GowinSemicoductor
 * Chip		: AE350_SOC
 * Function	: Triple mode Ethernet driver definitions
 * ******************************************************************************************
 * */

#ifndef __ETHERNET_H__
#define __ETHERNET_H__


// Includes ---------------------------------------------------------------------------------
#include "platform.h"
#include "Driver_Common.h"


// Definitions  -----------------------------------------------------------------------------

// Register definition
typedef struct
{
	union
	{
		__O  unsigned int ETH_TX_DATA[384];     /* 0x000~0x5ff transmit data registers          */
		__I  unsigned int ETH_RX_DATA[384];     /* 0x000~0x5ff receive data registers           */
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

// Memory map definition
#define ETHERNET_BASE		AHB_EXT_BASE		/* Ethernet base address                        */

// Device definitions
#define AE350_ETHERNET		((ETHERNET_RegDef *) ETHERNET_BASE)
#define DEV_ETHERNET		AE350_ETHERNET

// Interrupt definition
// Use IRQ_GP0_SOURCE
// Use gp0_irq_handler

// Bit definition
#define BIT0                  (1UL << 0)

#define ETH_TX_LATE_COL       (1UL << 2)
#define ETH_TX_EXCESSIVE_COL  (1UL << 1)
#define ETH_TX_FAIL_FAIL      (1UL << 0)

#define MIIM_OP_END_IS        (1UL << 1)
#define MIIM_RD_DATA_VALID_IS (1UL << 0)

#define MIIM_OP_END_IE        (1UL << 1)
#define MIIM_RD_DATA_VALID_IE (1UL << 0)

#define MIIM_OP_END_IC        (1UL << 1)
#define MIIM_RD_DATA_VALID_IC (1UL << 0)

#define ETH_DUPLEX_MODE       (1UL << 2)

#define ETH_FULL_DUPLEX_100M    0UL
#define ETH_FULL_DUPLEX_1000M   1UL
#define ETH_FULL_DUPLEX_10M     2UL
#define ETH_HALF_DUPLEX_100M    4UL
#define ETH_HALF_DUPLEX_10M     6UL

#define ETH_RX 0
#define ETH_TX 1

// Debug
//#define DEBUG_PRINT


// Access structure of the Ethernet driver
typedef struct _AE350_DRIVER_ETHERNET
{
	int32_t (*init)             (uint8_t *rx_ptr, uint32_t *rx_data_length, uint32_t *miim_rd_ptr);			// Initializes
	int32_t (*eth_tx)           (uint8_t *tx_message, uint32_t tx_length);									// Transmit
	void    (*miim_write)       (uint8_t miim_phy_address, uint8_t miim_reg_addr, uint16_t miim_wr_data);	// MIIM write
	void    (*miim_receive)     (uint8_t miim_phy_address, uint8_t miim_reg_addr);							// MIIM receive
	void    (*eth_set_mode)     (uint32_t eth_mode);														// Set working mode
} const AE350_DRIVER_ETHERNET;

// Ethernet information
typedef struct _ETHERNET_INFO
{
	uint8_t  *rx_ptr;
	uint32_t *rx_data_length;
	uint32_t *miim_rd_ptr;
} ETHERNET_INFO;


#endif		/* __ETHERNET_H__ */
