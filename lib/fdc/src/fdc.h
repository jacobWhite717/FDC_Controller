#ifndef FDC_H
#define FDC_H

#include <Arduino.h>
#include "fdcsensor.h"

class FDC 
{
public:
    FDC(bool sensor2 = false, bool sensor2_3 = false, int address = 0x2A, long refFrequency = 40*pow(10,6));

    void setupSensor(int sensorNum, FDCSensor sensor);
    // FDCSensor sensor(int num);

    int writeFDC(byte regAddr, unsigned int regVal);

    unsigned int readFDC(byte regAddr);    

    unsigned int sensorRaw(int sensorNum);

    long sensorFreq(int sensorNum, bool MHz = true);

    double sensorCap(int sensorNum, bool pF = true);

private:    //helpers
    unsigned int fetchDataAddress(int sensorNum);

private:
   const int _I2C_Addr;
   const long _fRef;
   FDCSensor _sensors[4];
};

#endif  // FDC_H