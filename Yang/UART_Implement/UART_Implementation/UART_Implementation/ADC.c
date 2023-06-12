/*
 * ADC.c
 *
 * Created: 22/08/2022 13:30:43
 *  Author: Daniel
 */ 
#include <stdint.h>
#include <avr/io.h>

void adc_init(void){
	ADMUX = (1 << REFS0);
	ADCSRA |= (1 << ADEN) | (4 << ADPS0) | (1 << ADATE);
	ADCSRB = (1 << ADTS0) | (2 << ADTS0);
	DIDR0 = 0b00000000;
	
	
	EICRA = (2 << ISC00);
	
	
}

uint16_t adc_read(uint8_t channel){
	ADMUX &= 0xF0;
	ADMUX |= channel;
	
	ADCSRA |= (1 << ADSC);
	
	while((ADCSRA & (1 << ADIF)) == 0){
		;
	}
	
	return((ADCL << 0) | (ADCH << 8));
}