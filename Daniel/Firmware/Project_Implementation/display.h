/*
 * display.h
 *
 * Created: 30/09/2022 13:41:54
 *  Author: Daniel Martinez
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>

volatile uint8_t disp_position;
static volatile uint8_t disp_characters[4];
void display_init(void);
void seperate_and_load_characters(uint16_t number, uint8_t decimal_pos);
void send_next_character_to_display(void);



#endif /* DISPLAY_H_ */