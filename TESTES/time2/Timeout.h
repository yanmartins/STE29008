/*
 * Timeout.h
 *
 *  Created on: 10/05/2019
 *      Author: aluno
 */


#ifndef TIMEOUT_H_
#define TIMEOUT_H_

#include <avr/io.h>

typedef void (*CALLBACK_t)(void);

class TIMEOUT {
public:
	uint32_t _interval;
	void callback(){(* _callback)();};
	void checkTimeout();
	void config(uint32_t interval, CALLBACK_t callback);
	TIMEOUT();
	bool is_event();
	bool is_enable();
	void e_event();
	void d_event();

private:
	bool _event;
	bool _enable;
	CALLBACK_t _callback;
	uint32_t _counter;
};

#endif /* TIMEOUT_H_ */
