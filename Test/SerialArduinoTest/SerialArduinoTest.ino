void setup() {
  Serial.begin(9600);
  pinMode(15,OUTPUT);
}

void loop() {
  byte inByte;
  if(Serial.available())
  {
    inByte = Serial.read();
    for(byte i = 1; i <= inByte*2; i++)
    {
      digitalWrite(15, !digitalRead(15));
      delay(200);
    }
  }
}
