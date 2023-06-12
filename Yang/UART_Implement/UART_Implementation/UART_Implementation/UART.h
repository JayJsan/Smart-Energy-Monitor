/*
 * header.h
 *
 * Created: 22/08/2022 11:43:50
 *  Author: Daniel
 */ 


#ifndef HEADER_H_
#define HEADER_H_
#include <stdint.h>



void uart_init(uint16_t ubrr);
void uart_transmit(uint16_t data);




#endif /* HEADER_H_ */