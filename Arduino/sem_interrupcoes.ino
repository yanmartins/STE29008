
int ledPin1 = 8;
int s1 = 2;

void setup() {
  Serial.begin(9600);
  pinMode(s1, INPUT);
  pinMode(ledPin1, OUTPUT);
}

void loop() {
  digitalWrite(ledPin1, HIGH);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  
  digitalWrite(ledPin1, LOW);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
  verifica_botao();
  delay(100);
}

void verifica_botao(){
  if(digitalRead(s1)){
    Serial.println("Oi");
    return;
  }
}
