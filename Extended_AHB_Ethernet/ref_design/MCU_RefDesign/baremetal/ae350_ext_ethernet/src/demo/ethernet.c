/*
 * ******************************************************************************************
 * File		: ethernet.c
 * Author	: GowinSemicoductor
 * Chip		: AE350_SOC
 * Function	: Triple mode Ethernet driver definitions
 * ******************************************************************************************
 * */

// Includes ---------------------------------------------------------------------------------
#include "ethernet.h"

#ifdef DEBUG_PRINT
#include <stdio.h>
#endif


// Definitions ------------------------------------------------------------------------------

// Ethernet information
static ETHERNET_INFO ethernet_info = {NULL, NULL, NULL};


// Ethernet transmit interrupt event
void tx_int_event(void)
{
	if(!DEV_ETHERNET->ETH_TX_FAIL)
	{
		DEV_ETHERNET->ETH_TX_IC |= BIT0;
	}
	else if(DEV_ETHERNET->ETH_TX_FAIL & ETH_TX_EXCESSIVE_COL)
	{
		DEV_ETHERNET->ETH_TX_EN |= BIT0;
		DEV_ETHERNET->ETH_TX_IC |= BIT0;
	}
	else if(DEV_ETHERNET->ETH_TX_FAIL & ETH_TX_LATE_COL)
	{
		DEV_ETHERNET->ETH_TX_EN |= BIT0;
		DEV_ETHERNET->ETH_TX_IC |= BIT0;
	}
}

// Ethernet receive interrupt event
void rx_int_event(void)
{
	uint8_t *rx_message = ethernet_info.rx_ptr;
	uint32_t *rx_data_length = ethernet_info.rx_data_length;

	if(rx_message == NULL)
	{
		return;
	}

	uint32_t rx_length = DEV_ETHERNET->ETH_RX_LENGTH;
	*rx_data_length = rx_length;
	uint8_t *rx_buffer = (uint8_t *)(DEV_ETHERNET->ETH_RX_DATA);

	for(int i = 0; i < rx_length; i++)
	{
		rx_message[i] = rx_buffer[i];
	}

	DEV_ETHERNET->ETH_RX_IC |= BIT0;
}

// MIIM write interrupt event
void miim_wr_int_event(void)
{
	uint32_t miim_is = DEV_ETHERNET->MIIM_IS;

	DEV_ETHERNET->MIIM_IC |= miim_is;
}

// MIIM read interrupt event
void miim_rd_int_event(void)
{
	uint32_t *miim_rd_data = ethernet_info.miim_rd_ptr;

	if(miim_rd_data == NULL)
	{
		return;
	}

	*miim_rd_data = DEV_ETHERNET->MIIM_RD_DATA;
	uint32_t miim_is = DEV_ETHERNET->MIIM_IS;
	DEV_ETHERNET->MIIM_IC |= miim_is;
}

// Initializes Ethernet
int32_t eth_init(uint8_t* rx_ptr, uint32_t *rx_data_length, uint32_t *miim_rd_ptr)
{
	DEV_ETHERNET->ETH_TX_LENGTH = 0;
	DEV_ETHERNET->ETH_TX_EN = 0;
	DEV_ETHERNET->ETH_TX_FAIL = 0;
	DEV_ETHERNET->ETH_TX_IE = 1;
	DEV_ETHERNET->ETH_RX_IE = 1;
	DEV_ETHERNET->MIIM_OP_MODE = 0;
	DEV_ETHERNET->MIIM_PHY_ADDR = 0;
	DEV_ETHERNET->MIIM_REG_ADDR = 0;
	DEV_ETHERNET->MIIM_WR_DATA = 0;
	DEV_ETHERNET->MIIM_IE = 1;
	DEV_ETHERNET->MIIM_OP_EN = 0;
	DEV_ETHERNET->ETH_MODE = 0;

	ethernet_info.rx_ptr = rx_ptr;
	ethernet_info.rx_data_length = rx_data_length;
	ethernet_info.miim_rd_ptr = miim_rd_ptr;

	return 0;
}

// Ethernet transmit
int32_t eth_tx (uint8_t *tx_message, uint32_t tx_length)
{
	while(DEV_ETHERNET->ETH_TX_EN);

	DEV_ETHERNET->ETH_TX_LENGTH = tx_length;

	uint32_t *tx_message_ptr = (uint32_t *)(tx_message);
	uint32_t tx_word_num = tx_length / 4 + (tx_length % 4 ? 1 : 0);

	for(int i = 0; i < tx_word_num; i++)
	{
		DEV_ETHERNET->ETH_TX_DATA[i] = tx_message_ptr[i];
	}

	DEV_ETHERNET->ETH_TX_EN |= BIT0;

	return 0;
}

// MIIM write
void miim_write(uint8_t miim_phy_address, uint8_t miim_reg_addr, uint16_t miim_wr_data)
{
	DEV_ETHERNET->MIIM_IE = 0x03;
	DEV_ETHERNET->MIIM_OP_MODE = 1;
	DEV_ETHERNET->MIIM_PHY_ADDR = miim_phy_address;
	DEV_ETHERNET->MIIM_REG_ADDR = miim_reg_addr;
	DEV_ETHERNET->MIIM_WR_DATA = miim_wr_data;
	DEV_ETHERNET->MIIM_OP_EN = 1;
}

// MIIM receive
void miim_receive(uint8_t miim_phy_address, uint8_t miim_reg_addr)
{
	DEV_ETHERNET->MIIM_IE = 0x03;
	DEV_ETHERNET->MIIM_OP_MODE = 0;
	DEV_ETHERNET->MIIM_PHY_ADDR = miim_phy_address;
	DEV_ETHERNET->MIIM_REG_ADDR = miim_reg_addr;
	DEV_ETHERNET->MIIM_OP_EN = 1;
}

// Set working mode
void eth_set_mode(uint32_t eth_mode)
{
	DEV_ETHERNET->ETH_MODE = eth_mode;
}

// Ethernet interrupt handler : gp0_irq_handler
void gp0_irq_handler(void)
{
	if(DEV_ETHERNET->ETH_RX_IS)
	{
#ifdef DEBUG_PRINT
		printf("Ethernet RX Interrupt Enable Register : %d\r\n",DEV_ETHERNET->ETH_RX_IE);
#endif
		DEV_ETHERNET->ETH_RX_IE = 0;
		rx_int_event();
		DEV_ETHERNET->ETH_RX_IE = 1;
	}
	else if(DEV_ETHERNET->ETH_TX_IS)
	{
#ifdef DEBUG_PRINT
		printf("Ethernet TX  Interrupt Enable Register : %d \r\n",DEV_ETHERNET->ETH_TX_IE);
#endif
		DEV_ETHERNET->ETH_TX_IE = 0;
		tx_int_event();
		DEV_ETHERNET->ETH_TX_IE = 1;
	}
	else if(DEV_ETHERNET->MIIM_IS & 0x1)
	{
#ifdef DEBUG_PRINT
		printf("Ethernet MIIM1 Interrupt Status Register : %d\r\n",DEV_ETHERNET->MIIM_IS&0x1);
#endif
		DEV_ETHERNET->MIIM_IE = 0;
		miim_rd_int_event();
		DEV_ETHERNET->MIIM_IE = 3;
	}
	else if(DEV_ETHERNET->MIIM_IS & 0x2)
	{
#ifdef DEBUG_PRINT
		printf("Ethernet MIIM2 Interrupt Status Register : %d\r\n",DEV_ETHERNET->MIIM_IS&0x2);
#endif
		DEV_ETHERNET->MIIM_IE = 0;
		miim_wr_int_event();
		DEV_ETHERNET->MIIM_IE = 3;
	}
}

// Ethernet driver control block
AE350_DRIVER_ETHERNET Driver_ETHERNET =
{
	eth_init,			// Initializes
	eth_tx,				// Transmit
	miim_write,			// MIIM write
	miim_receive,		// MIIM receive
	eth_set_mode		// Set working mode
};
