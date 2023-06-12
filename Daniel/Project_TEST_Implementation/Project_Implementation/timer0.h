/*
 * timer0.c
 *
 * Created: 27/09/2022 16:15:02
 *  Author: Daniel Martinez
 */ 
#include <avr/io.h>
#include <stdbool.h>


#ifndef TIMER0_H_
#define TIMER0_H_

void disable_timer();
volatile uint16_t counterValue;
volatile uint8_t runOnce;
void timer0_init();


#endif /* TIMER0_H_ */