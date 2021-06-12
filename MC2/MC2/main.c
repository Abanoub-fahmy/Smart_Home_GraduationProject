/*
 * MC2.c
 *
 * Created: 6/11/2021 9:38:55 PM
 * Author : Infotech
 */ 

#include "SPI.h"
#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
	uint8 tx_data = 2;
	uint8 rx_data = 0;
	
	/*Init LED*/
	DIO_SetPinDir(DIO_PORTC , DIO_PIN1 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTC , DIO_PIN2 , DIO_PIN_OUTPUT);
	
	SPI_Slave_Init();
	
	
	
	while (1)
	{
		
		
		rx_data = SPI_TranSiver(1);
		
		if(rx_data == '1')
		{
			DIO_SetPinValue(DIO_PORTC , DIO_PIN1,DIO_PIN_HIGH);
			rx_data = 0;
		}
		if(rx_data == '2')
		{
			DIO_SetPinValue(DIO_PORTC , DIO_PIN1,DIO_PIN_LOW);
			rx_data = 0;
		}
		if(rx_data == '3')
		{
			DIO_SetPinValue(DIO_PORTC , DIO_PIN2,DIO_PIN_HIGH);
			rx_data = 0;
		}
		if(rx_data == '4')
		{
			DIO_SetPinValue(DIO_PORTC , DIO_PIN2,DIO_PIN_LOW);
			rx_data = 0;
		}
		_delay_ms(1000);
	}
}
