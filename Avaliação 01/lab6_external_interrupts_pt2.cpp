#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

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

void interrupt_handler(){
	while (PINE & (1 << PE4)){ 	// Enquanto o botão estiver pressionado
		PORTH |= (1 << PH6);	// Led permanece aceso
	}
	PORTH &= ~(1 << PH6);	// Senão apaga
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

