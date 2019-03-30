/**
 *
 *****************************************************************
 * IOT Challenges - https://instagram.com/iotchallenges          *
 *****************************************************************
 * Evandro Fruhauf                                               *
 *  GitHub - https://github.com/evandrodp                        *
 *  LinkedIn - http://linkedin.com/in/evandrofruhauf             *
 *****************************************************************
 * This code can contain parts from other open-sources projects, *
 * whenever possible it will be quoted.                          *
 *****************************************************************
 *
 * Water Sensor
 *
 * Challenge: Detect the water and define 3 levels using Leds
 *
**/
#include <Arduino.h>

// define sensor pin
#define SENSOR A5

// define LEDs pins
int greenLed = 8;
int yellowLed = 9;
int redLed = 10;

// initialise the states
int greenState = LOW;
int yellowState = LOW;
int redState = LOW;

// define limits for the detection
int greenLimit = 300;
int yellowLimit = 480;
int sensorValue;

void setup() {
  Serial.begin(9600);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  sensorValue = analogRead(SENSOR);
  Serial.println(sensorValue);
  if (sensorValue < greenLimit) {
    if (greenState == LOW) {
      Serial.println("Turn on GREEN");
      digitalWrite(greenLed, HIGH);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, LOW);
      greenState = HIGH;
      yellowState = LOW;
      redState = LOW;
    }
  } else if (sensorValue < yellowLimit) {
    if (yellowState == LOW) {
      Serial.println("Turn on YELLOW");
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, HIGH);
      digitalWrite(redLed, LOW);
      greenState = LOW;
      yellowState = HIGH;
      redState = LOW;
    }
  } else {
    if (redState == LOW) {
      Serial.println("Turn on RED");
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, HIGH);
      greenState = LOW;
      yellowState = LOW;
      redState = HIGH;
    }
  }
  delay(100);
}