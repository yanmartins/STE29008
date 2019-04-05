/*
 * gpio.h
 *
 *  Created on: 03/04/2019
 *      Author: aluno
 */

#include <avr/io.h>

#ifndef GPIO_H_
#define GPIO_H_

class GPIO {
public:
	enum PortDirection_t{
		INPUT = 0,
		OUTPUT = 1
	};

	GPIO (uint8_t id, PortDirection_t dir);
	~GPIO();

	bool read();
	void write(bool val);
	void toggle();

private:
	volatile uint8_t *_pin;
	volatile uint8_t *_ddr;
	volatile uint8_t *_port;
	
	uint8_t _bit; // valor no datasheet
	uint8_t _id; // valor no arduino
};

#endif /* GPIO_H_ */
