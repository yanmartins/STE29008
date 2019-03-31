#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

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

uint16_t read_adc(uint8_t channel){
	ADMUX &= 0xE0;           	// Limpa bits de MUX0-4
	ADMUX |= channel & 0x07;   	// Define um novo canal a ser lido by setting bits MUX0-2
	ADCSRB = channel & (1<<3); 	// Define MUX5 como zero
	ADCSRA |= (1<<ADSC);      	// Inicia uma nova conversão
	while(ADCSRA & (1<<ADSC));  	// Aguarda até que a conversão seja finalizada
	return ADCW; 			// Retorna o valor ADC do canal escolhido
}


void adc_init(void){
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)); // Determina o fator de divisão como 128
	ADMUX |= (1<<REFS0);    // Define a tensão de referencia do AVCC (5V)
	ADCSRA |= (1<<ADEN);    // ADC Enable, ativa o ADC
	ADCSRA |= (1<<ADSC);	// Inicia uma conversão incial
}


double RMS (int repeat){

	double digital_value;
	double average;
	double accumulated = 0;

	uint8_t channel = 0;	// Canal utilizado para leitura ADC (Porta A0)

	for (int i = 0; i <= repeat; i++){
		digital_value = read_adc(channel);
		accumulated = (digital_value*digital_value) + accumulated;
	}
	average = accumulated/repeat;
	return sqrt(average);
}

double to_analog(double valor){
	double analogico;
	analogico = valor*(5.0/1023.0);
	return analogico;
}


int main(){
	USART_Init(MYUBRR);	// Inicia interface de comunicação
	adc_init();		// Inicia interface de leitura ADC
	double val = 0;
	double val_analogico = 0;

	while (true){

			val = RMS(100);			// Converte valor lido para RMS
			val_analogico = to_analog(val); // Converte valor RMS para analógico

			char buffer_dig [5];
			char buffer_analog [5];

//			itoa(val,buffer_dig,10);
//			itoa(val_analogico,buffer_analog,10);

			dtostrf(val,5,3,buffer_dig);			// Converte o valor double para um vetor char
			dtostrf(val_analogico,5,3,buffer_analog);

			char palavra_dig[10] = "Digital: ";
			for (int i = 0; i < 9; i ++){			// Laço para transmissão da palavra
				USART_Transmit(palavra_dig[i]);
			}

			for (int i = 0; i < 5; i ++){			// Laço para transmissão dos valores digitais
				USART_Transmit(buffer_dig[i]);
			}
			USART_Transmit('\t');	// Utilizado para formatação da saída

			char palavra_analog[12] = "Analogico: ";
			for (int i = 0; i < 11; i ++){			// Laço para transmissão da palavra
				USART_Transmit(palavra_analog[i]);
			}

			for (int i = 0; i < 5; i ++){
				USART_Transmit(buffer_analog[i]);	// Laço para transmissão dos valores analógicos
			}
			USART_Transmit('\n');	// Utilizado para formatação da saída

			_delay_ms(1000);
		}
}

