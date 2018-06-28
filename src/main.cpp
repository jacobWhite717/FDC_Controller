#include <Arduino.h>
#include <Wire.h>
#include <fdc.h>
#include <fdcsensor.h>

FDC fdc(true);
FDCSensor sensor0(33*pow(10, -12), 18*pow(10, -6)); 
FDCSensor sensor1(33*pow(10, -12), 18*pow(10, -6)); 

void setup() {
  Serial.begin(9600);
  Wire.begin();

  fdc.setupSensor(0, sensor0);
  fdc.setupSensor(1, sensor1);
}

void loop() {
  Serial.print("Sensor0: ");
  Serial.print(fdc.sensorCap(0));
  Serial.println("pF");
  Serial.print("Sensor1: ");
  Serial.print(fdc.sensorCap(1));
  Serial.println("pF");  
}
