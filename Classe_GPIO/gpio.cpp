/*
 * gpio.cpp
 *
 *  Created on: 03/04/2019
 *      Author: aluno
 */


#include "gpio.h"


GPIO::GPIO(uint8_t id, PortDirection_t dir){
	_id = id;

	 switch (_id){

	 case 2:
	 case 3:
		 _bit = id + 2;
		 if(dir == INPUT){
			 DDRE &= ~(1<<_bit);
		 }
		 else {
			 DDRE |= (1<<_bit);
		 }
		 break;

	 case 4:
		 if(dir == INPUT){
			 DDRG &= ~(1<<PG5);
		 }
		 else {
			 DDRG |= (1<<PG5);
		 }
	 	break;

	 case 5:
		 if(dir == INPUT){
			 DDRE &= ~(1<<PE3);
		 }
		 else {
			 DDRE |= (1<<PE3);
		 }
	 	break;

	 case 6:
	 case 7:
	 case 8:
	 case 9:
		 _bit = id - 3;

		 if(dir == INPUT){
			 DDRH &= ~(1<< _bit);
		 }
		 else {
			 DDRH |= (1<< _bit);
		 }
	 	break;
	 }
}

bool GPIO::read(){

}

void GPIO::write(bool val){

}

void GPIO::toggle(){

}
