/*
 * ******************************************************************************************
 * File		: main.c
 * Author 	: GowinSemicoductor
 * Chip		: AE350_SOC
 * Function	: Main functions
 * ******************************************************************************************
 */

// Includes ---------------------------------------------------------------------------------
#include "uart.h"
#include <stdio.h>
#include "delay.h"
#include "ethernet.h"


// Definitions ------------------------------------------------------------------------------

#define TX_LENTGH 72

uint8_t  rx_data[1536];
uint8_t  tx_data[1536];
uint32_t rx_data_length = 0;
uint32_t miim_rd_data = 0;
uint32_t tx_length = TX_LENTGH;

extern AE350_DRIVER_ETHERNET Driver_ETHERNET;

uint8_t tx_data[] =
{
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
	0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
	0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
	0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
	0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
	0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
	0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88
};


// Application entry function
int main(void)
{
	// Initializes UART2
	uart_init(38400);	// Baud rate is 38400

	printf("\r\nIt's an Extended AHB Ethernet demo.\r\n\r\n");

	AE350_DRIVER_ETHERNET *ETH_Dri = &Driver_ETHERNET;

	uint8_t  *rx_data_ptr = rx_data;
    uint32_t *rx_data_length_ptr = &rx_data_length;
    uint32_t *miim_rd_data_ptr = &miim_rd_data;

    // Initializes Ethernet
	ETH_Dri->init(rx_data_ptr, rx_data_length_ptr, miim_rd_data_ptr);

	// Priority must be set > 0 to trigger the interrupt
	HAL_INTERRUPT_SET_LEVEL(IRQ_GP0_SOURCE, 2);

	// Enable PLIC interrupt PIT source
	HAL_INTERRUPT_ENABLE(IRQ_GP0_SOURCE);

	// Enable the Machine-External bit in MIE
	set_csr(NDS_MIE, MIP_MEIP);

	// Enable GIE
	set_csr(NDS_MSTATUS, MSTATUS_MIE);

	// Set Ethernet working mode : 1000MHz
	ETH_Dri->eth_set_mode(ETH_FULL_DUPLEX_1000M);

	uint8_t  *tx_ptr = (uint8_t *)tx_data;

	while(1)
	{
		// Transmit
		ETH_Dri->eth_tx(tx_ptr, tx_length);

		simple_delay_ms(500);

		printf("Complete an Ethernet TX.\r\n");
	}

	return 0;
}
