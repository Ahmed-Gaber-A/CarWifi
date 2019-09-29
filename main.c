/*
 * wifi.c
 *
 * Created: 9/29/2019 11:17:05 AM
 * Author : Bobpo
 */ 

#include "ESP_Driver.h"
#include "uart_driver.h"
#include "motor.h"
#include "DIO.h"
#include "ESB_WIFI.h"
#include "PWM.h"

uint8_t Reading_g;
void CallBack_Function (uint8_t data)
{
	Reading_g = data;
}
int main(void)
{
    /* Replace with your application code */
	UART_Init(9600,CallBack_Function);
	motor_init();
	ESP_WIFI_Init();
	pwm_init();
	sei();
	DIO_SetPinDirection(PIN13,OUTPUT);
			DIO_WritePin(PIN13,HIGH);
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

