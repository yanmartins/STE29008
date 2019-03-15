float val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = RMS(30);
  
  Serial.print("Digital: ");
  Serial.println(val);

  Serial.print("Analogico: ");
  Serial.println(to_analog(val));
  Serial.println();
  
  delay(1000);
}

float RMS(int repeat){
  float digital_value;
  float average;
  float accumulated = 0;
  
  for (int i = 0; i <= repeat; i++) {
    digital_value = analogRead(A1);
    accumulated = digital_value*digital_value + accumulated;
  }
    average = accumulated / repeat;
    return sqrt(average);
}


float to_analog(float valor){
  float analogico;
  analogico = valor*(5.0/1023.0);
  return analogico;
}
