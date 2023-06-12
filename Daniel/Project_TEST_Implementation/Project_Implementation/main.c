/*
 * Project_Implementation.c
 *
 * Created: 11/10/2022 13:32:16
 * Author : Daniel Martinez
 */ 

#include <avr/io.h>
#include "common.h"
#include "display.h"
#include "timer0.h"
#include "uart.h"
#include "adc.h"
#include "zeroXing.h"
#include "calculation.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint16_t mainCounter = 0;

//Custom printf function
int uart_printf(char var, FILE *stream){
	uart_transmit(var);
	return 0;
}
static FILE usart_stdout = FDEV_SETUP_STREAM(uart_printf, NULL, _FDEV_SETUP_WRITE);

void testfunction() {
	cli();
	printf("bruhmomentV6");
	printf("\n\r");

	// --------------------------------- Voltage and Current Data
	printf("voltage = [");
	for (uint8_t i = 0; i < sampleSize; i++){
		printf("%f, ", voltageArray[i]);
	}
	printf("];");
	printf("\n\r");
	printf("current = [");
	for (uint8_t i = 0; i < sampleSize; i++){
		printf("%f, ", currentArray[i]);
		
	}
	printf("];");
	printf("\n\r");
	// --------------------------------- RMS Calculation
	
	
	printf("RMSVoltage = [");
	printf(" %f ", RMSVoltage);
	printf("]");
	printf("\n\r");
	
	printf("RMSCurrent = [");
	printf(" %f ", RMSCurrent);
	printf("]");
	printf("\n\r");
	
	
	// --------------------------------- Voltage and Current LA Calculation
	
	printf("VoltageLA = [");
	for (uint16_t i = 0; i < sampleSize; i++){
		printf("%f, ", approxVoltageArray[i]);
		
	}
	printf("];");
	printf("\n\r");
	printf("CurrentLA = [");
	for (uint16_t i = 0; i < sampleSize; i++){
		printf("%f, ", approxCurrentArray[i]);
	}
	
	printf("];");
	printf("\n\r");
	
	
	printf("RMSPower = [");
	printf(" %f ", RMSPower );
	printf("]");
	printf("\n\r");
}



int main(void)
{
	DDRB = 0x00;
	DDRC = 0x00;
	DDRD = 0x00;
	
	uart_init(12);
	stdout = &usart_stdout;
	timer0_init();
	display_init();
	adc_init();
	
	//zeroXing_init();
	
	sceneSwitch = 0; //set scene to ADC
	sei();
	
	
	
	
	DDRB |= (1 << PORTB5); //led debug
	
	while (1)
	{
		switch (sceneSwitch) {
			case 0:
				// Sample Mode
				disable_timer();
				zeroXing_init();
				
				break;
				
			case 1:
				// UART MODE
				timer0_init(); //re-enabe timer
				
 				printf("RMS Voltage is: %f\n\r", 13.9);
 				printf("RMS Current is: %f \n\r", 167.0);
 				printf("Power is: %f \n\r", 6.5);
 				printf("\n\r");
				//printf("%d, %d, %d, %c",disp_characters[3], disp_characters[2], disp_characters[1], disp_characters[0]);
								
				sceneSwitch = 2; //set back to (0)sample mode or (2)Display Mode_____
				
				break;
				
			case 2:
				// Display Mode

				
				if (counterValue > 400){ //executed every 400ms
					counterValue = 0;
					
					switch(displayMode){
						case 0:
							seperate_and_load_characters(RMSVoltage * 10, 0);
							sceneSwitch = 0;
							break;
						case 1:
							seperate_and_load_characters(RMSCurrent, 0);
							sceneSwitch = 0;
							break;
						case 2:
							seperate_and_load_characters(RMSPower * 100, 0);
							sceneSwitch = 0;
							break;
						default:
							printf("This shii brooooke");
						
					}
					displayMode++;
					
				}
				//printf("%d \n\r", disp_characters[0]);
				//sceneSwitch = 0;
				
				break;
				
			case 3:
				testfunction();
				break;
				
			case 100:
				//BufferMode
				//waiting for zeroxing to cross
				break;
				
			default:
				printf("This shii brooooke");
		}

	}
}


