/*
 * adc.h
 *
 * Created: 22/08/2022 13:24:33
 *  Author: Daniel Martinez
 */ 

#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

void adc_init();
uint16_t adc_read(uint8_t chan);
void adc_convert_mv();
void adc_interrupt_disable();


uint8_t arraycount;


#endif /* ADC_H_ */