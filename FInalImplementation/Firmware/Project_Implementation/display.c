/*
 * display.c
 *
 * Created: 30/09/2022 13:41:40
 *  Author: Daniel Martinez
 */ 

#include "display.h"
#include "uart.h"
#include "common.h"
#include <avr/io.h>
#include <avr/interrupt.h>

//Array containing which segments to turn on to display a number between 0 to 9
const uint8_t seg_pattern[13]={0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111, 0b00111110, 0b01110111, 0b01110011};
//const uint8_t seg_pattern[10]={0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};

//4 characters to be displayed on Ds1 to Ds 4
static volatile uint8_t disp_characters[4]={0,0,0,0};
		
	
//The current digit (e.g. the 1's, the 10's) of the 4-digit number we're displaying
volatile uint8_t disp_position = 0;

void display_init(void){
	//Configure DDR bits of the I/O pins connected to the display

	DDRC |= (1 << PORTC5) | (1 << PORTC4) | (1 << PORTC3);
	
	DDRD |= (1 << PORTD7) | (1 << PORTD6) | (1 << PORTD5) | (1 << PORTD4);
}



//Populate the array �disp_characters[]� by separating the four digits of �number�
//and then looking up the segment pattern from �seg_pattern[]�
void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos){
	//mod calculation
	uint8_t seg1Number = number % 10;
	uint8_t seg2Number = ((number - seg1Number) % 100) / 10;
	uint8_t seg3Number = ((number - seg1Number - (seg2Number * 10)) % 1000) / 100;



	//loading calculation into array
	disp_characters[0] =  seg_pattern[10 + displayMode]; //unit
	disp_characters[1] = seg_pattern[seg1Number]; //ones
	disp_characters[2] = seg_pattern[seg2Number]; //tens
	disp_characters[3] = seg_pattern[seg3Number]; //hundreds
	
	//switch to see if decimal point is needed for display mode
	switch(displayMode){
		case 0:
			disp_characters[2] |= (1 << 7);
			break;
		case 2:
			disp_characters[3] |= (1 << 7);
			break;	
	}
	
	
}


//Render a single digit from �disp_characters[]� on the display at �disp_position�
void send_next_character_to_display(void){

	//reset all display pins
	PORTD |= (1 << PORTD4);
	PORTD |= (1 << PORTD5);
	PORTD |= (1 << PORTD6);
	PORTD |= (1 << PORTD7);
	
	//switch case to check which segment needs to be output
	switch (disp_position){
		case 0:
			PORTD &= ~(1 << PORTD7);
			break;
		case 1:
			PORTD &= ~(1 << PORTD6);
			break;
		case 2:
			PORTD &= ~(1 << PORTD5);
			break;
		case 3:
			PORTD &= ~(1 << PORTD4);
			break;
		
		
	}
			
		//SHIFTING CODE. MUST STAY AS IS
		//______________________________
		uint8_t number = disp_characters[disp_position];
		for (int i = 8; i > 0; i--){
			//reset latch and shift pin
			PORTC &= ~(1 << PORTC3);
			PORTC &= ~(1 << PORTC5);
			
			if(number & (1 << (i-1))){ //checks if bit is 1
				PORTC |= (1 << PORTC4); //writes 1 to data
				PORTC |= (1 << PORTC3); //sets shift pin
			} else {
				PORTC &= ~(1 << PORTC4); // writes 0 to data
				PORTC |= (1 << PORTC3);// sets shift pin
			}
		}
		PORTC |= (1 << PORTC5); //latching
		//______________________________
	
	
	disp_position++;
}