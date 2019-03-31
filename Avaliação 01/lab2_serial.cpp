#include <avr/io.h>
#include <util/delay.h>

#define FOSC 16000000		// Define velocidade do clock
#define BAUD 9600		// Define baudrate
#define MYUBRR (FOSC/16/BAUD-1) // Define a frequência de oscilação

void USART_Init( unsigned int ubrr){
	UBRR0 = ubrr;				// Define a frequência de oscilação
	UCSR0B = (1<<RXEN0)|(1<<TXEN0); 	// Habilita RX e TX
	UCSR0C = (1<<USBS0)|(3<<UCSZ00); 	// Define formato do frame: 8 data, 2 stop bit
}

void USART_Transmit( unsigned char data ){
	while ( !( UCSR0A & (1<<UDRE0)) ); 	// Aguarda o buffer de transmissão ficar vazio
	UDR0 = data; // Armazena os dados no buffer, transmite os dados
}

unsigned char USART_Receive( void ){
		while (!(UCSR0A & (1<<RXC0))); 	// Aguarda que dados sejam recebidos
		return UDR0; // Obtem e retorna os dados recebidos do buffer
	}

int main( void ) {
	USART_Init(MYUBRR); // Inicia interface de comunicação
	unsigned char info;

	while(true){
		info = USART_Receive();
		info++;
		USART_Transmit(info);
	}
}
