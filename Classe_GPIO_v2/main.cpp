#include <avr/interrupt.h>
#include <util/delay.h>
#include "gpio.h"

GPIO led1(7, GPIO::OUTPUT);


int main(void){

	while (1){
		led1.toggle();
		_delay_ms(1000);
	}
}
