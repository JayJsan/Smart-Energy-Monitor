/*
 * calculation.c
 *
 * Created: 16/10/2022 6:08:02 pm
 *  Author: dmar256
 */ 
#include "common.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

//convert ADC values to voltage and offset by opamp circuitry
void adc_convert_mv(){
	for (uint16_t i = 0; i < sampleSize; i++){
		voltageArray[i] = (float)((voltageArray[i] * (float)Vref/adc_count) - VoffsetV) / (Gvs*Gvo);
		currentArray[i] = (float)((currentArray[i] * (float)Vref/adc_count) - VoffsetC) / (Gis*Gio);
	}
}

//calculates and returns RMS
float RMS_calculation(float array[]){
	float sum = 0;
	float RMS = 0;

	for (uint16_t i = 0; i < 80; i++) {
		sum = sum + pow(array[i],2);
	}
	
	RMS = sum / sampleSize;
	RMS = sqrt(RMS);
	
	return RMS;
}

//uses linear approximation to 'guess' missing samples while multiplexing
//guess first missing current reading
void current_linear_approx() {
	memset(approxCurrentArray, 0, sampleSize);
	
	approxCurrentArray[0] = ((0) + currentArray[0]) / 2 ;
	
	for (uint8_t i = 1; i < sampleSize; i++) {
		approxCurrentArray[i] = (currentArray[i-1] + currentArray[i]) / 2;
	}
}

//uses linear approximation to 'guess' missing samples while multiplexing
//guess last missing voltage reading
void voltage_linear_approx() {
	memset(approxVoltageArray, 0, sampleSize);

	for (uint8_t i = 0; i < sampleSize-1; i++) {
		approxVoltageArray[i] = (voltageArray[i] + voltageArray[i+1]) / 2;
	}

	approxVoltageArray[sampleSize-1] = (float)((approxVoltageArray[sampleSize-2]*2) + approxVoltageArray[sampleSize-2]) / 2;
}

//calculates RMS power by using a precalculated scalar
float RMS_power_calculation(){
	float sum = 0;
	float scalar = 0;
	
	scalar = ((float)(1-((float)RMSCurrent/132.0861)/30) - 0.0333333);

	sum = RMSCurrent * RMSVoltage * scalar / 1000;
	
	return sum;
}

//a distributer function to make global calculation calls easier
void convertValues(){
	adc_convert_mv();
	voltage_linear_approx();
	current_linear_approx();
	
	RMSVoltage = (float)RMS_calculation(voltageArray) / 1000;
	RMSCurrent = RMS_calculation(currentArray);
	RMSPower = RMS_power_calculation();
}