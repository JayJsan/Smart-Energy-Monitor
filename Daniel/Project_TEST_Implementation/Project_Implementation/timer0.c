/*
 * timer0.c
 *
 * Created: 27/09/2022 16:15:02
 *  Author: Daniel Martinez
 */ 
#include "common.h"
#include "timer0.h"
#include "uart.h"
#include "display.h"
#include <stdio.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile uint16_t counterValue = 0;


void timer0_init(){
	TCCR0A |= (1 << WGM01);
	TCCR0B |= (1 << CS01) | (1<<CS00);
	TIMSK0 |= (1 << OCIE0A);
	
	OCR0A = 100;
	
}


void disable_timer(){
	TCCR0A &= ~(1 << WGM01);
	
	TIMSK0 &= ~(1 << OCIE0A);
	TCNT0 = 0b00000000;
	disp_position = 0;
}


volatile uint16_t timerup = 0;

//triggered every 1ms;
ISR(TIMER0_COMPA_vect) {
	//uart_transmit('h');
	
	
		
	//triggered every 10ms
	if(timerup > 10){
		
		send_next_character_to_display();
			
		if(displayMode > 2){
			displayMode = 0;
			//TIMSK0 &= ~(1 << OCIE0A);
			//sceneSwitch = 0;
		}
		
		if(disp_position > 3){ //reset
			disp_position = 0;
			
		}
		
		counterValue++;
		
	}else{
		timerup++;
	}

	
}