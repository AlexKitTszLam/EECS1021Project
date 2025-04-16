int led1pin = 15;
int led2pin = 13;
int led3pin = 11;

//sound sensor vars
int soundSensorPin = A0;
long previousClapTime = millis();
double soundSensorReading;

//pwm light control vars
int rotationSensorPin = A1;  //pin32
int lightLevel;              //used sensor goes from 0 -> 1023
int pwmValue;

bool led1Toggle = false, led2Toggle = false, led3Toggle = false;


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
    byte HOME_ACTION = receivedNum;
    Serial.print("Received: ");
    Serial.println(HOME_ACTION);  // Debugging statement to check what is received
    switch (receivedNum) {
      case 1:
        Serial.println("Toggling LED 1");
        led1Toggle = !led1Toggle;
        break;
      case 2:
        Serial.println("Toggling LED 2");
        led2Toggle = !led2Toggle;
        break;
      case 3:
        Serial.println("Toggling LED 3");
        led3Toggle = !led3Toggle;
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

  //PWM Switches
  lightLevel = analogRead(rotationSensorPin);
  pwmValue = map(lightLevel, 0, 1023, 0, 255); //convert signal from 1023 max to 255 max

  if (led1Toggle) {
    analogWrite(led1pin, pwmValue);
  } else {
    analogWrite(led1pin, 0);
  }

  if (led2Toggle) {
    analogWrite(led2pin, pwmValue);
  } else {
    analogWrite(led2pin, 0);
  }

  if (led3Toggle) {
    analogWrite(led3pin, pwmValue);
  } else {
    analogWrite(led3pin, 0);
  }




  //sound sensor code
  soundSensorReading = analogRead(soundSensorPin);
  if (soundSensorReading > 17 && (millis() - previousClapTime > 300)) {
    Serial.println("detected clap");
    previousClapTime = millis();  // Reset the timer

    // Toggle LED 1 if enabled
    if (led1Clap) {
      led1Toggle = !led1Toggle;
    }

    // Toggle LED 2 if enabled
    if (led2Clap) {
      led2Toggle = !led2Toggle;
    }

    // Toggle LED 3 if enabled
    if (led3Clap) {
      led3Toggle = !led3Toggle;
    }
  }
}
