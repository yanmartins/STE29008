/*
 * gpio.cpp
 *
 *  Created on: 4 de abr de 2019
 *      Author: yan
 */

#include "gpio.h"


GPIO::GPIO(uint8_t id, PortDirection_t dir){
	_id = id;

	 switch (_id){

	 case 2:
	 case 3:
		 _bit = id + 2;
		 _port = &PORTE;
		 _ddr = &DDRE;
		 _pin = &PINE;
		 break;

	 case 4:
		 _bit = PG5;
		 _port = &PORTG;
		 _ddr = &DDRG;
		 _pin = &PING;
	 	break;

	 case 5:
		 _bit = PE3;
		 _port = &PORTE;
		 _ddr = &DDRE;
		 _pin = &PINE;
	 	break;

	 case 6:
	 case 7:
	 case 8:
	 case 9:
		 _bit = id - 3;
		 _port = &PORTH;
		 _ddr = &DDRH;
		 _pin = &PINH;
	 	break;
	 }
	
	 if(dir == INPUT){
		 _ddr &= ~(1<< _bit);
	 }
	 else {
		 _ddr |= (1<< _bit);
	 }
}

bool GPIO::read(){
	return _pin & (1<<_bit);
}

void GPIO::write(bool val){
	if(val){
		_port |= (1 << _bit);
	}
	else{
		_port &= ~(1 << _bit);
	}
}

void GPIO::toggle(){
	_port ^= (1 << _bit);
}

