/*
 * uart_mapping.h
 *
 *  Created on: 29 de mai de 2019
 *      Author: yan
 */

#include <stdio.h>
#include "uart.h"
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {

	UART uart0(0, 9600, UART::NORMAL_SPEED, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
	UART uart1(1, 9600, UART::NORMAL_SPEED, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
	UART uart2(2, 9600, UART::NORMAL_SPEED, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
	UART uart3(3, 9600, UART::NORMAL_SPEED, UART::DATABITS_8, UART::NONE, UART::STOPBIT_1);
	sei();

	char data0[] = "zero";
	char data1[] = "um";
	char data2[] = "dois";
	char data3[] = "tres";

	uart0.puts(data0);
	uart1.puts(data1);
	uart2.puts(data2);
	uart3.puts(data3);

		while(true){
			if(uart0.has_data()){
				uint8_t data = uart0.get();
				uart0.put(data);
			}
			if(uart1.has_data()){
				uint8_t data = uart1.get();
				uart1.put(data);
			}
			if(uart2.has_data()){
				uint8_t data = uart2.get();
				uart2.put(data);
			}
			if(uart3.has_data()){
				uint8_t data = uart3.get();
				uart3.put(data);
			}

		}
}
