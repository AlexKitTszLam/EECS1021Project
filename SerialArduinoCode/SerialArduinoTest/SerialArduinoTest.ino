int led1pin = 15;
int led2pin = 13;
int led3pin = 11;

//sound sensor vars
int soundSensorPin = A0;
long previousClapTime = millis();
double soundSensorReading;

//clapper toggle vars
bool led1Clap = false;
bool led2Clap = false;
bool led3Clap = false;

void setup() {
  Serial.begin(9600);
  pinMode(led1pin, OUTPUT);
  pinMode(led2pin, OUTPUT);
  pinMode(led3pin, OUTPUT);
}

void loop() {

  //serial inputs
  if (Serial.available() > 0) {
    char receivedNum = Serial.read();
    byte HOME_ACTION = receivedNum - '0';
    Serial.print("Received: ");
    Serial.println(HOME_ACTION);  // Debugging statement to check what is received
    switch (HOME_ACTION) {
      case 1:
        Serial.println("Toggling LED 1");
        digitalWrite(led1pin, !digitalRead(led1pin));
        break;
      case 2:
        Serial.println("Toggling LED 2");
        digitalWrite(led2pin, !digitalRead(led2pin));
        break;
      case 3:
        Serial.println("Toggling LED 3");
        digitalWrite(led3pin, !digitalRead(led3pin));
        break;

      case 4:
        Serial.println("Toggling led 1 clapper");
        led1Clap = !led1Clap;
        break;
      case 5:
        Serial.println("Toggling led 2 clapper");
        led2Clap = !led2Clap;
        break;
      case 6:
        Serial.println("Toggling led 3 clapper");
        led3Clap = !led3Clap;
        break;
      default:
        Serial.println("Unknown command received.");
        break;
    }
  }

  //sound sensor code
  soundSensorReading = analogRead(soundSensorPin);
  if (soundSensorReading > 17 && (millis() - previousClapTime > 300)) {
    Serial.println("detected clap");
    previousClapTime = millis();  // Reset the timer

    // Toggle LED 1 if enabled
    if (led1Clap) {
      digitalWrite(led1pin, !digitalRead(led1pin));
    }

    // Toggle LED 2 if enabled
    if (led2Clap) {
      digitalWrite(led2pin, !digitalRead(led2pin));
    }

    // Toggle LED 3 if enabled
    if (led3Clap) {
      digitalWrite(led3pin, !digitalRead(led3pin));
    }
  }
}
