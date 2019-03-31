#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <time.h>

#define FOSC 16000000
#define BAUD 9600
#define debounce_limit 200

void interrupt_init(){
	DDRE &= ~(1 << PE4);	// Define D2 como input (S1)
	DDRH |= (1 << PH6);		// Define D9 como output (LED1)

	EICRB = (1 << ISC40)|(1 << ISC41); 	// Sensível a borda de subida
	EIMSK |= (1 << INT4);				// Pino externo de interrupção ativo (D2)

	sei();		// Permite executar interrupções, ativa a máscara de interrupção global
}

//bool debounce(){
//	long now;
//	long tempo;
//
//	now = clock();
//
//	if((now - tempo) > debounce_limit) {
//	  tempo = now;
//	  return true;
//	}
//	else
//	  return false;
//}

void interrupt_handler(){
//if(debounce()){
		PORTH ^= (1 << PH6);
//	}
}

int main(){

	PORTH &= ~(1 << PH6);	// Envia 0 para porta D9
	interrupt_init();

	while(true){
		if(PINE & (1 << PE4)){	// Se o botão for pressionado
			interrupt_handler(); // então é gerada a interrupção
		}
	}
}

