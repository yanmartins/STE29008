/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include "gpio.h"

GPIO::GPIO(int pin, PortDirection_t dir)
: _pin(pin)
{
	 switch (pin){

	 case 2:
	 case 3:
		 _pin = pin + 2;
		 _port = GPIO_PORT::PE;
		 break;

	 case 4:
		 _pin = pin + 1;
		 _port = GPIO_PORT::PG;
	 	break;

	 case 5:
		 _pin = pin - 2;
		 _port = GPIO_PORT::PE;
	 	break;

	 case 6:
	 case 7:
	 case 8:
	 case 9:
		 _pin = pin - 3;
		 _port = GPIO_PORT::PH;
	 	break;
	 }

	_port->dir(_pin, dir);
}

GPIO::~GPIO() {}

bool GPIO::get() {
	return _port->get(_pin);
}

void GPIO::set(bool val) {
	_port->set(_pin, val);
}

void GPIO::clear() {
	this->set(0);
}

void GPIO::toggle() {
	_port->toggle(_pin);
}
