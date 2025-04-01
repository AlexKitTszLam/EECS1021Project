int led1pin = 15;
int led2pin = 13;
int led3pin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(led1pin,OUTPUT);
  pinMode(led2pin,OUTPUT);
  pinMode(led3pin,OUTPUT);

}

void loop() {
  if(Serial.available() > 0) {
    char receivedNum = Serial.read();
    byte HOME_ACTION = receivedNum - '0';
    Serial.print("Received: ");
    Serial.println(HOME_ACTION);  // Debugging statement to check what is received
    switch (HOME_ACTION) {
      case 1:
        Serial.println("Toggling LED 1");
        if (digitalRead(led1pin) == LOW) {
          digitalWrite(led1pin, HIGH);
        } else {
          digitalWrite(led1pin, LOW);
        }
        break;
      case 2:
        Serial.println("Toggling LED 2");
        if (digitalRead(led2pin) == LOW) {
          digitalWrite(led2pin, HIGH);
        } else {
          digitalWrite(led2pin, LOW);
        }
        break;
      case 3:
        Serial.println("Toggling LED 3");
        if (digitalRead(led3pin) == LOW) {
          digitalWrite(led3pin, HIGH);
        } else {
          digitalWrite(led3pin, LOW);
        }
        break;
      default:
        Serial.println("Unknown command received.");
        break;
    }
  }
}
