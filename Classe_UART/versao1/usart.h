/*
 * usart.h
 *
 *  Created on: 12/04/2019
 *      Author: aluno
 */


#ifndef USART_H_
#define USART_H_

class USART {
public:
	enum DATABITS_t{
		DATABITS_5 = 0,
		DATABITS_6 = 2,
		DATABITS_7 = 4,
		DATABITS_8 = 6
	};

	enum PARITY_t{
		NONE = 0,
		EVEN = 32,
		ODD = 48
	};

	enum STOPBITS_t{
		STOPBIT_1 = 0,
		STOPBIT_2 = 8
	};

	USART(uint8_t id, uint32_t baud, DATABITS_t db, PARITY_t parity, STOPBITS_t sb);
	~USART();

	void put(uint8_t data);
	void puts(const char * data);
	uint8_t get();

private:
	uint8_t _id;

};


#endif /* USART_H_ */
