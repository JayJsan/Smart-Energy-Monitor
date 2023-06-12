/*
 * ADC.h
 *
 * Created: 22/08/2022 13:30:33
 *  Author: danie
 */ 

#include <stdint.h>
#ifndef ADC_H_
#define ADC_H_

void adc_init(void);
uint16_t adc_read(uint8_t channel);



#endif /* ADC_H_ */