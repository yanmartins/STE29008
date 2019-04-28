
int ledPin1 = 8;
int ledPin2 = 9;

int s1 = 2;
int s2 = 3;

void setup() {
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
    if(digitalRead(s2)){
      digitalWrite(ledPin1, HIGH);
    }
    else if(!digitalRead(s1)){
      digitalWrite(ledPin2, HIGH);
    }
    else{
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
    }
}
