/*
 * main.cpp
 *
 *  Created on: 24/04/2019
 *      Author: aluno
 */

#include <stdio.h>
#include "uart.h"
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {

	UART serial(0, 9600, UART::NORMAL_SPEED, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
	uint8_t info;
	sei();

	while(true){
		if(serial.has_data()){
			info = serial.get();
			serial.put(info);
			//_delay_ms(500);
		}
	}
}
