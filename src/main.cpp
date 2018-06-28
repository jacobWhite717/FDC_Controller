#include <Arduino.h>
#include <Wire.h>
#include "fdc.h"

FDC fdc;
FDC::Sensor sensor0_1 = {
  3*pow(10, -12),
  18*pow(10, -6)
};

void setup() {
  Serial.begin(9600);
  Wire.begin();

  fdc.setupSensor(0, sensor0_1);
  // fdc.setupSensor(1, sensor0_1);
}

void loop() {
  Serial.print("Sensor0: ");
  // Serial.print(fdc.sensorCap(0, true));
  Serial.println("pF");
  Serial.print("Sensor1: ");
  // Serial.print(fdc.sensorCap(1));
  Serial.println("pF");  
  Serial.println("");
  delay(2000);
}
