#include <avr/io.h>
#include <util/delay.h>

int main(){

	DDRE &= ~(1<<PE4);	// Define D2 como input (S1)
	DDRE &= ~(1<<PE5);	// Define D3 como input (S2)

	DDRH |= (1<<PH5);	// Define D8 como output (LED1)
	DDRH |= (1<<PH6);	// Define D9 como output (LED2)


	while(true){

		// Quando S1 for pressionado o LED1 acenderá
		if(!(PINE & (1<<PE4))){		// Lógica negada devido resistor pull-down
			PORTH |= (1 << PH5);
		}
		// Caso contrário, apagará
		else{
			PORTH &= ~(1 << PH5);
		}

		// Quando S2 for pressionado o LED2 acenderá
		if(PINE & (1<<PE5)){
			PORTH |= (1 << PH6);
		}
		// Caso contrário, apagará
		else{
			PORTH &= ~(1 << PH6);
		}
	}
}

