/*
 * UART.c
 *
 * Created: 22/08/2022 11:48:54
 *  Author: Daniel
 */ 

#include <stdint.h>
#include <avr/io.h>


void uart_init(uint16_t ubrr){
	//UCSR0A = 0b00000000;
	UCSR0B = (1<<TXEN0);
	//UCSR0C = 0b00000110; //this is initial value. Don't really need this line
	
	UBRR0 = ubrr;
}

void uart_transmit(uint16_t data){
	while ((UCSR0A & 0b00100000) == 0){
		;
	}
	
	UDR0 = data;
}

