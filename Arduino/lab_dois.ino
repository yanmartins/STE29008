byte byte_recived;
int baud_rate = 9600;

void setup() {
  Serial.begin(baud_rate);
}

void loop() {
  if(Serial.available()){
    while(1){
      byte_recived = Serial.read();
      Serial.println(byte_recived);
    }
  }
}
