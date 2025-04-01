int led1pin = 15;
int led2pin = 13;
int led3pin = 11;

//Sound sensor pin
int soundPin = A0;


void setup() {
  Serial.begin(9600);
  pinMode(led1pin,OUTPUT);
  pinMode(led2pin,OUTPUT);
  pinMode(led3pin,OUTPUT);

}

void loop() {
  if(Serial.available() > 0)
  {
    byte HOME_ACTION = Serial.read();
    switch (HOME_ACTION){
      case 1:
        Serial.print("Code detected");
        if (digitalRead(led1pin == LOW)){
          digitalWrite(led1pin, HIGH);
          delay(1500);
        }
        else{
          digitalWrite(led1pin, LOW);
          delay(1500);
        }
        break;
      case 2:
        Serial.print("Code detected");
        if (digitalRead(led2pin == LOW)){
          digitalWrite(led2pin, HIGH);
          delay(1500);
        }
        else{
          digitalWrite(led2pin, LOW);
          delay(1500);
        }
        break;
      case 3:
        Serial.print("Code detected");
        if (digitalRead(led3pin == LOW)){
          digitalWrite(led3pin, HIGH);
          delay(1500);
        }
        else{
          digitalWrite(led3pin, LOW);
          delay(1500);
        }
        break;
    }
  }
}
