/*
 * UART_Implementation.c
 *
 * Created: 22/08/2022 11:39:09
 * Author : Daniel
 */ 
#define F_CPU 2000000UL

#include <avr/io.h>
#include "UART.h"
#include "ADC.h"
#include <stdio.h>
#include <util/delay.h>
#include <string.h>


#define RMSVoltage 20.0
#define RMSCurrent 199
#define Power 2.20


//init printf functions
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
		//prints volotage, current, power values using pringf
		printf("RMS Voltage is: %03.1f \n\r", RMSVoltage);
		printf("RMS Current is: %d \n\r", (uint16_t)RMSCurrent);
		printf("Power is: %03.2f \n\r", Power);
		printf("\n\r");
		
		//adding delay
		_delay_ms(1000);
		
    }
}

