/*
 * MC1.c
 *
 * Created: 6/11/2021 8:47:31 PM
 * Author : Infotech
 */ 

#include "LCD.h"
#include "UART.h"
#include "SPI.h"
#define F_CPU 16000000
#include <util/delay.h>


int main(void)
{
	uint8 data1 = 0;

	UART_Init();
	LCD_Init();
	
	uint8 tx_data = 1;
	uint8 rx_data = 0;
	
	
	
	SPI_Master_Init();
	SPI_Master_InitTrans();
	_delay_ms(1000);
	
    /* Replace with your application code */
    while (1) 
    {
		data1 = UART_Rx();
		
		if(data1)
		{
			LCD_Clear();
			LCD_WriteChar(data1);
			rx_data = SPI_TranSiver(data1);
					//_delay_ms(1000);

			
		}
		
		
		
		
		
    }
}

