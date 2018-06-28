#ifndef FDC_H
#define FDC_H

#include <Arduino.h>

class FDC 
{
public:

    struct Sensor {
        double tankCap;
        double tankInd;
    };

    FDC(bool ADDR_pin_H = false, long refFrequency = 40*pow(10,6));

    void INIT(bool sensor2 = false, bool sensor2_3 = false);

    void setupSensor(int sensorNum, FDC::Sensor sensor);
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
    FDC::Sensor _sensors[4];
};

#endif  // FDC_H