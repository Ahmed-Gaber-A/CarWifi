/*
 * ESP_WIFI.c
 *
 * Created: 9/29/2019 6:24:04 PM
 *  Author: Bobpo
 */ 

#include "ESB_WIFI.h"
//#define F_CPU 8000000 ULL

void ESP_WIFI_Init(void)
{
	UART_Write_String("AT+CWMODE=2");
	UART_Write_Byte(0xD);
	UART_Write_Byte(0xA);
	_delay_ms(1000);
	UART_Write_String("AT+CIPMUX=1");
	UART_Write_Byte(0xD);
	UART_Write_Byte(0xA);
	_delay_ms(1000);
	UART_Write_String("AT+CIPSERVER=1,2222");
	UART_Write_Byte(0xD);
	UART_Write_Byte(0xA);
	_delay_ms(1000);
	UART_Write_String("AT+CWSAP=\"BOBO123\",\"EKRAM123\",1,3");
	UART_Write_Byte(0xD);
	UART_Write_Byte(0xA);
	_delay_ms(1000);
}
