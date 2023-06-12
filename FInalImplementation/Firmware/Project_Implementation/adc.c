/*
 * adc.c
 *
 * Created: 02/09/2022 13:11:24
 *  Author: Daniel Martinez
 */ 

#include "common.h"
#include "adc.h"
#include "uart.h"
#include "calculation.h"
#include "timer0.h"
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>

uint8_t arraycount;

void adc_init(){
	
	arraycount = 0;
	
	ADMUX = 0b01000000;
	ADCSRA = 0b00100100;//pre of 16, Autotrigger
	ADCSRB = 0b00000000; //interrupt request
	
// 	ADMUX |= (1 << MUX0); //set MUX to read ADC 1
// 	ADMUX &= ~(1 << MUX0); //set mux to read ADC 0
	
	ADCSRA |= (1<< ADEN) | (1<< ADSC); //enable adc and start conversion
	

}




void adc_interrupt_disable(){
	ADCSRA &= ~(1<< ADIE); //disable int
	
}


ISR(ADC_vect){
	
	//if 80 samples taken, disable ADC and change scene
	if(arraycount > 79){
		adc_interrupt_disable();
		convertValues();
		
		sceneSwitch = 1; //set scene to (3)Testing mode or (1)UART mode_____
		timer0_init(); //re-enabe timer
	
	//save adc in appropriate array
	}else if((ADMUX & (1<<MUX0)) == 0){
		currentArray[arraycount] = ADC;
		arraycount++;
	}else if (ADMUX & (1<<MUX0)) {
		voltageArray[arraycount] =  ADC;

	}
	
	ADMUX ^= (1 << MUX0);
	

}

