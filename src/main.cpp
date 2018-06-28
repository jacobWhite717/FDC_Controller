#include <Arduino.h>
#include <Wire.h>
#include "fdc.h"

FDC fdc;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  fdc.INIT();
  fdc.setupSensor(0, {33*pow(10, -12), 18*pow(10, -6)});
  fdc.setupSensor(1, {33*pow(10, -12), 18*pow(10, -6)});
}

void loop() {
  Serial.print("Sensor0: ");
  Serial.print(fdc.sensorCap(0));
  Serial.println("pF");

  Serial.print("Sensor1: ");
  Serial.print(fdc.sensorCap(1));
  Serial.println("pF"); 

  Serial.println("");
  delay(2000);
}
