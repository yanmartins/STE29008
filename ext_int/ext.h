/*
 * ext.h
 *
 *  Created on: 08/05/2019
 *      Author: aluno
 */


#ifndef EXTINT_H_
#define EXTINT_H_
#include <avr/io.h>
#include <avr/interrupt.h>

typedef void (*CALLBACK_t)(void);

class EXTINT {
public:

	enum INT_ID_t{
		INT_0 = 0,
		INT_1 = 1,
		INT_2 = 2,
		INT_3 = 3,
		INT_4 = 4,
		INT_5 = 5,
		INT_6 = 6,
		INT_7 = 7
	};

	enum ISC_t{
		LOW_LEVEL = 0,
		ANY_EDGE = 1,
		FALLING = 2,
		RISIGN = 3
	};

	EXTINT(INT_ID_t id, ISC_t cfg, CALLBACK_t _pCallback);
	void callback(){(* _pCallback)();};
	void enable();
	void disable();

	static EXTINT * _Extint_singletons[8];

private:
	CALLBACK_t _pCallback;
	uint8_t _id;
};

#endif /* EXTINT_H_ */
