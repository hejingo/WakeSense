#include <PulseSensorPlayground.h>


const int pulsePin = A1; 
const int buzzerPin = 9;  

PulseSensorPlayground pulseSensor; 

int heartRate;        // variable to store the heart rate value
int threshold = 100;  // heart rate threshold for alarm trigger (adjustable)

void setup() {
  Serial.begin(9600);  // start

  // set pin mode for buzzer
  pinMode(buzzerPin, OUTPUT);

  // initialize pulsesensor object
  pulseSensor.analogInput(pulsePin);  // set the input pin for the pulse sensor
  pulseSensor.begin();               // initialize the sensor
}

void loop() {
  int BPM = pulseSensor.getBeatsPerMinute();  // get bpm

  if (BPM > 0) {  // if bpm is valid
    heartRate = BPM;  // store the heart rate value
    Serial.print("Heart Rate: ");
    Serial.println(heartRate);  // print to serial monitor
  }

  // trigger buzz if exceeds threshold 
  if (heartRate > threshold) {
    tone(buzzerPin, 1000);  // activate the buzzer 
  } else {
    noTone(buzzerPin);      // deactivate the buzzer if heart rate is below threshold
  }

  delay(1000);  // delay before checking again
}