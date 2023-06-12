/*
 * uart.h
 *
 * Created: 8/09/2022 1:50:16 pm
 *  Author: Daniel Martinez
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

void uart_init(uint16_t ubrr);
void uart_transmit(uint16_t data);
void uart_transmit_array(char* message);




#endif /* UART_H_ */