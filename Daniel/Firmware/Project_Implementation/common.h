/*
 * common.h
 *
 * Created: 06/09/2022 14:21:07
 *  Author: Daniel Martinez
 */ 


#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>
#include <time.h>
#include <stdio.h>

#define F_CPU 2000000UL

#define Vref 5000UL //Vref in mV
#define adc_count 1024UL

#define Gvs 0.04347
#define Gvo 0.95
#define Gis 0.6
#define Gio 1.9

 
#define VoffsetV 2070 //in mV
#define VoffsetC 2070 //in mV

#define sampleSize 80


uint8_t sceneSwitch; //0 for ADC, 1 for UART, 2 for Display
uint8_t displayMode; //0 for Voltage, 1 for Current, 2 for Power

float currentArray[sampleSize];
float voltageArray[sampleSize];
float approxCurrentArray[sampleSize];
float approxVoltageArray[sampleSize];

float RMSVoltage; //voltage in V
float RMSCurrent; //current in mA
float RMSPower; //power in W


#endif /* COMMON_H_ */