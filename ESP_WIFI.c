/***********************************************
 *  Module:ESB_WIFI
 *
 *  File Name:ESB_WIFI.c
 *
 *  Description: ESB WIFI  function implementation
 *
 *  Created on : 29/9/2019
 *
 *  Author: Ahmed Ekram&Ahmed Gaber
 ***********************************************/
/************************************************************************
*			             Included Libraries                              *
************************************************************************/
#include "ESB_WIFI.h"

/**************************************************************************
 * Function Name : ESP_WIFI_Init
 *
 * Description	 : Operate AT Commands and setting SSID and pw to it
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
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
