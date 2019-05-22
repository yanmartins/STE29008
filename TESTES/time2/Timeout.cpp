/*
 * Timeout.cpp
 *
 *  Created on: 10/05/2019
 *      Author: aluno
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timeout.h"

TIMEOUT::TIMEOUT(){}

void TIMEOUT::checkTimeout(){
	if(_counter == _interval){
		_counter = 0;
		_event = true;
	}
	else {
		_counter = _counter + 1;
		_event = false;
	}
}

void TIMEOUT::config(uint32_t interval, CALLBACK_t callback) {
	_interval = interval;
	_callback = callback;
	_counter = 0;
	_enable = true;
	_event = false;
}

bool TIMEOUT::is_event(){
	return _event;
}

bool TIMEOUT::is_enable(){
	return _enable;
}

void TIMEOUT::e_event(){
	_event = true;
}

void TIMEOUT::d_event(){
	_event = false;
}
