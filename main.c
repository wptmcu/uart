/*
 * uart_test.c
 *
 * Created: 2023-07-28 오후 5:40:55
 * Author : WARP000046N
 */ 

#define F_CPU (4000000UL)

#include <avr/io.h>
#include <string.h>
#include <util/delay.h>
#include "uart.h"

int main(void)
{
	UART_init();
	while (1)
	{
		//Output to "UART4 serial" serial every 1000ms
		 UART_sendString("UART4 serial\r\n");
		_delay_ms(1000);
	}
}

