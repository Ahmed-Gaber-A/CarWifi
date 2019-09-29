/***********************************************
 *  Module:Wifi Application
 *
 *  File Name:main.c
 *
 *  Description: Wifi functions implementation
 *
 *  Created on : 29/9/2019
 *
 *  Author: Ahmed Ekram&Ahmed Gaber
 ***********************************************/
/************************************************************************
*			             Included Libraries                              *
************************************************************************/
#include "ESP_Driver.h"
#include "uart_driver.h"
#include "motor.h"
#include "DIO.h"
#include "ESB_WIFI.h"
#include "PWM.h"
/*Global variable to store UDR value*/
uint8_t Reading_g;
/**************************************************************************
 * Function Name : CallBack_Function
 *
 * Description	 : it's function is to change a value of global variable by the value in UDR register according 
 *                 to the interrupt that occurs when UART of microcontroller recieve a byte via wifi
 * INPUTS		 : void
 * 
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void CallBack_Function (uint8_t data)
{
	Reading_g = data;
}
int main(void)
{
    /* Replace with your application code */
	/*Inilializing UART,MOTOR,ESP_WIFI and PWM*/
	UART_Init(9600,CallBack_Function);
	motor_init();
	ESP_WIFI_Init();
	pwm_init();
	/*Enabling global interrupts*/
	sei();
    while (1) 
    {
		if(Reading_g=='w')
		{
			motor_forward();
			pwm_write(100);
			DIO_SetPinDirection(PIN12,OUTPUT);
			DIO_WritePin(PIN12,HIGH);
        }
		else if(Reading_g=='s')
		{
			pwm_write(100);
			DIO_SetPinDirection(PIN13,OUTPUT);
			DIO_WritePin(PIN13,HIGH);
			motor_backward();
		}
		else if(Reading_g=='d')
		{
			pwm_write(100);
			motor_right();
			DIO_SetPinDirection(PIN14,OUTPUT);
			DIO_WritePin(PIN14,HIGH);
		}
		else if(Reading_g=='a')
		{
			pwm_write(100);
			motor_left();
			DIO_WritePin(PIN14,LOW);
			DIO_WritePin(PIN13,LOW);
			DIO_WritePin(PIN12,LOW);
		}
		else if(Reading_g=='q')
		{
		    motor_stop();	
		}
}
}

