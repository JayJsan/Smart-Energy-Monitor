/*
 * UART_Implementation.c
 *
 * Created: 23/08/2022 11:39:09
 * Author : Yang
 */ 
#define F_CPU 2000000UL

#include <avr/io.h>
#include "UART.h"
#include "ADC.h"
#include <stdio.h>
#include <util/delay.h>
#include <string.h>


#define RMSVoltage 14.5
#define RMSCurrent 125
#define Power 1.60



int uart_printf(char var, FILE *stream){
	uart_transmit(var);
	return 0;
}

static FILE usart_stdout = FDEV_SETUP_STREAM(uart_printf, NULL, _FDEV_SETUP_WRITE);



int main(void){
	
	uart_init(12); //Calling the initializing function
	stdout = &usart_stdout;	
	
	
    while (1) 
    {
		
		printf("RMS Voltage is: %03.1f \n\r", RMSVoltage);//Printing the info to the Virtual Terminal
		printf("RMS Current is: %d \n\r", (uint16_t)RMSCurrent);
		printf("Power is: %03.2f \n\r", Power);
		printf("\n\r");
			
		_delay_ms(1000);
		
    }
}

