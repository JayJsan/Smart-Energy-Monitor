/*
 * calculation.h
 *
 * Created: 16/10/2022 6:08:12 pm
 *  Author: dmar256
 */ 


#ifndef CALCULATION_H_
#define CALCULATION_H_

void convertValues();

void adc_convert_mv();

void current_linear_approx();

void voltage_linear_approx();

float RMS_calculation(float array[]);

float RMS_power_calculation();


#endif /* CALCULATION_H_ */