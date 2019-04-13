/*
 * usart.cpp
 *
 *  Created on: 12/04/2019
 *      Author: aluno
 */

#include <avr/io.h>
#include "usart.h"

USART::USART(uint8_t id, uint32_t baud, DATABITS_t db, PARITY_t parity, STOPBITS_t sb):
_id(id)
{
	switch(_id){
	case 0:
		UBRR0 = (16000000/16/baud-1);
		UCSR0B = (1<<RXEN0)|(1<<TXEN0);
		UCSR0C = db|parity|sb;
		break;
	case 1:
		UBRR1 = (16000000/16/baud-1);
		UCSR1B = (1<<RXEN1)|(1<<TXEN1);
		UCSR1C = db|parity|sb;
		break;
	case 2:
		UBRR2 = (16000000/16/baud-1);
		UCSR2B = (1<<RXEN2)|(1<<TXEN2);
		UCSR2C = db|parity|sb;
		break;
	case 3:
		UBRR3 = (16000000/16/baud-1);
		UCSR3B = (1<<RXEN3)|(1<<TXEN3);
		UCSR3C = db|parity|sb;
		break;
	}
}

USART::~USART() {}

uint8_t USART::get() {
	while (!(UCSR0A & (1<<RXC0))); 	// Aguarda que dados sejam recebidos
	return UDR0;
}

void USART::put(uint8_t data) {
	while ( !( UCSR0A & (1<<UDRE0)) ); 	// Aguarda o buffer de transmissão ficar vazio
	UDR0 = data; // Armazena os dados no buffer, transmite os dados
}

void USART::puts(const char * data) {
	for(int i = 0; data[i]!=0;i++)
		put((uint8_t) data[i]);
}

