/*
 * uart.c
 *
 * Created: 2023-07-28 오후 4:38:45
 *  Author: WARP000046N
 */

#define F_CPU (4000000UL)
#define USART4_BAUD_RATE(BAUD_RATE) ((float)(F_CPU*64/(16 *(float)BAUD_RATE)) + 0.5)

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "uart.h"

void UART_init(void)
{
	PORTE.DIR &= ~PIN1_bm;
	PORTE.DIR |= PIN0_bm;
	//UART register
	USART4.BAUD = (uint16_t)USART4_BAUD_RATE(115200);
	USART4.CTRLA |= USART_RXCIE_bm;
	USART4.CTRLB |= USART_TXEN_bm | USART_RXEN_bm;
	USART4.CTRLC |= USART_CHSIZE1_bm | USART_CHSIZE0_bm;
}

void UART_sendChar(char c)
{
	while (!(USART4.STATUS & USART_DREIF_bm))
	{
		;
	}
	USART4.TXDATAL = c;
}


void UART_sendString(char *str)
{
	for(size_t i = 0; i < strlen(str); i++)
	{
		UART_sendChar(str[i]);
	}
}
