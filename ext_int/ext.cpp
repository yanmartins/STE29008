/*
 * ext.cpp
 *
 *  Created on: 08/05/2019
 *      Author: aluno
 */

#include "ext.h"

uint8_t mask;
EXTINT * EXTINT::_Extint_singletons[8];

EXTINT::EXTINT(INT_ID_t id, ISC_t cfg, CALLBACK_t callback){
	_id = id;

	mask = (_id % 4) << 1;
	disable();

	if(_id<4){
		EICRA = (EICRA &~(3<<mask)) | (cfg << mask);
	} else {
		EICRB = (EICRB &~(3<<mask)) | (cfg << mask);
	}

	_pCallback = callback;
	_Extint_singletons[_id] = this;
}


void EXTINT::enable(){
	EIMSK |= (1 << _id);
}

void EXTINT::disable(){
	EIMSK &= ~(1 << _id);
}

ISR(INT0_vect){
	EXTINT::_Extint_singletons[0]->callback();
}

ISR(INT1_vect){
	EXTINT::_Extint_singletons[1]->callback();
}

ISR(INT2_vect){
	EXTINT::_Extint_singletons[2]->callback();
}

ISR(INT3_vect){
	EXTINT::_Extint_singletons[3]->callback();
}

ISR(INT4_vect){
	EXTINT::_Extint_singletons[4]->callback();
}

ISR(INT5_vect){
	EXTINT::_Extint_singletons[5]->callback();
}

ISR(INT6_vect){
	EXTINT::_Extint_singletons[6]->callback();
}

ISR(INT7_vect){
	EXTINT::_Extint_singletons[7]->callback();
}
