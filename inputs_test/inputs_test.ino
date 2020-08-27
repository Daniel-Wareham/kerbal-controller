int JBSValue;
int AGValue;
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  for (int i = 1; i <=16; i++) {  //set all pins to input
    pinMode(i, INPUT);
  }
  Serial.begin(115200);
}
//sssssssssssssssssssssss
void loop() {
  Serial.print("x: ");
  Serial.println(analogRead(A0));
  Serial.print("y: ");
  Serial.println(analogRead(A1));
  Serial.print("z: ");
  Serial.println(analogRead(A3));
  Serial.print("w: ");
  Serial.println(analogRead(A2));
  
  JBSValue = 2*digitalRead(15) + digitalRead(14);
  Serial.print("JBS: ");
  Serial.println(JBSValue);
  AGValue = 8*digitalRead(10) + 4*digitalRead(9) + 2*digitalRead(8) + digitalRead(7);
  Serial.print("AG: ");
  Serial.println(AGValue);

  Serial.print("mode: ");
  Serial.println(digitalRead(2));
  Serial.print("SAS: ");
  Serial.println(digitalRead(3));
  Serial.print("RCS: ");
  Serial.println(digitalRead(4));
  Serial.print("gears: ");
  Serial.println(digitalRead(5));
  Serial.print("lights: ");
  Serial.println(digitalRead(6));
  Serial.print("reset: ");
  Serial.println(digitalRead(16));
  
  Serial.println(" ");
  delay(200);
  
}
