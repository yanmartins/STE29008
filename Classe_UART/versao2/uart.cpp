/*
 * usart.cpp
 *
 *  Created on: 12/04/2019
 *      Author: aluno
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"


UART::UART(uint32_t baud, DATABITS_t db, PARITY_t parity, STOPBITS_t sb) {
	_has_data = false;
	UBRR0 = (16000000/16/baud-1);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0B = (1<<RXCIE0);
	UCSR0C = db|parity|sb;
}

UART::~UART() {}

uint8_t UART::get() {
	_has_data = false;
	return _rx_buffer;
}

void UART::put(uint8_t data) {
	_tx_buffer = data;
	UCSR0B |= (1<<UDRIE0);
}


bool UART::has_data(){
	return _has_data;
}

void UART::rx_isr_handler(USART0_RX_vect){
	_rx_buffer = UDR0;
	_has_data = true;
	reti(); // retorna de uma rotina de interrupção
}

void UART::tx_isr_handler(USART0_UDRE_vect){
	UDR0 = _tx_buffer;
	UCSR0B &= ~(1<<UDRIE0);
	reti();
}
