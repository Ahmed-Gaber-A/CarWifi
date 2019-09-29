
/***********************************************
 *  Module:ESB_WIFI
 *
 *  File Name:ESB_WIFI.H
 *
 *  Description: ESB WIFI declarations and function prototypes
 *
 *  Created on : 29/9/2019
 *
 *  Author: Ahmed Ekram&Ahmed Gaber
 ***********************************************/
#ifndef ESB_WIFI_H_
#define ESB_WIFI_H_
/************************************************************************
*			             Included Libraries                              *
************************************************************************/
#include "uart_driver.h"
#include <util/delay.h>

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
extern void ESP_WIFI_Init(void);


#endif /* ESB_WIFI_H_ */