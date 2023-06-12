/*
 * uart.c
 *
 * Created: 8/09/2022 1:47:34 pm
 *  Author: Daniel Martinez
 */ 

#include <stdint.h>
#include <avr/io.h>
#include <string.h>



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

void uart_transmit_array(char* message){
	for(uint8_t i = 0; i<strlen(message); i++){
		uart_transmit(message[i]);
	}
}