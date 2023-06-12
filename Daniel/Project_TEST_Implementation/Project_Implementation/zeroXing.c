/*
 * zeroXing.c
 *
 * Created: 14/10/2022 11:07:32 am
 *  Author: dmar256
 */ 

#include "common.h"
#include "zeroXing.h"
#include "adc.h"
#include "timer0.h"

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

uint8_t crossCount = 0;

void zeroXing_init(){
	EICRA |= (1 << ISC00) | (1 << ISC01); //rising edge on int0
	EIMSK |= (1 << INT0); //interupt enable
	sceneSwitch = 100;
}



ISR(INT0_vect){
		EIMSK &= ~(1 << INT0); //disable xing
		arraycount = 0;
 		while ((UCSR0A & ADSC) == 1){
 			;
 		}
 		ADMUX ^= (1 << MUX0);
		ADCSRA |= (1 << ADIE); //ENABLE ADC INTERUPT
		
	
}