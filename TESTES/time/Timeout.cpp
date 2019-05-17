/*
 * Timeout.cpp
 *
 *  Created on: 10/05/2019
 *      Author: aluno
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timeout.h"

void TIMEOUT::config(uint32_t interval, CALLBACK_t callback) {
	_interval = interval;
	_callback = callback;
}


void TIMEOUT::checkTimeout(){

}
