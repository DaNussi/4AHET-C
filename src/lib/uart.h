/*
 * uart.h
 *
 *  Created on: 15.06.2022
 *      Author: werne
 */

#ifndef LIB_ADC_H_
#define LIB_ADC_H_
#include <avr/io.h>

unsigned char adc_in_8bit(char channel);
void uart_transmit( unsigned char data );
void uart_init_default();

#endif /* LIB_ADC_H_ */