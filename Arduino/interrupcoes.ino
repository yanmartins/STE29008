// VERTIFICAR DOCUMENTAÇÃO DO attachInterrupt

int interrupcao_pin = 0;
int estado_led = 0;
int debounce_limit = 200;
int sensitivity = HIGH;  

int ledPin1 = 8;
int s1 = 2;

void setup() {
  Serial.begin(9600);
  pinMode(s1, INPUT);
  pinMode(ledPin1, OUTPUT);
}

void loop() {
  digitalWrite(ledPin1, estado_led);
  verifica_botao();
}

void verifica_botao(){
  if(digitalRead(s1)){
    interrupt_handler();
  }
}

void interrupt_handler(){
  if (debounce()){
      estado_led = !estado_led;
  }
}

int debounce(){ 
  long now;
  long tempo;
  
  now = millis();
  if((now - tempo) > debounce_limit) {
      tempo = now;
      return 1;
  }
  else
      return 0;
}
