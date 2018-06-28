#include <fdc.h>
#include <Wire.h>

FDC::FDC(bool sensor2, bool sensor2_3, int address, long refFrequency) :
    _I2C_Addr(address),
    _fRef(refFrequency)
{
    writeFDC(0x08, 0xFFFF);         //RCOUNT    
    writeFDC(0x09, 0xFFFF);         //^    
    writeFDC(0x0A, 0xFFFF);         //^
    writeFDC(0x0B, 0xFFFF);         //^
    writeFDC(0x10, 0x0400);         //SETTLECOUNT    
    writeFDC(0x11, 0x0400);         //^       
    writeFDC(0x12, 0x0400);         //^       
    writeFDC(0x13, 0x0400);         //^       
    writeFDC(0x14, 0x1001);         //CLOCK_DIVIDERS       
    writeFDC(0x15, 0x1001);         //^      
    writeFDC(0x16, 0x1001);         //^      
    writeFDC(0x17, 0x1001);         //^      
    writeFDC(0x19, 0x0000);         //ERROR_CONFIG  
    if(!sensor2 and !sensor2_3) {   //MUX_CONFIG
        writeFDC(0x1B, 0x820C);
    }
    else if(sensor2 and !sensor2_3) {
        writeFDC(0x1B, 0xA20C);
    }
    else {
        writeFDC(0x1B, 0xC20C);
    }     
    writeFDC(0x1E, 0x8C40);         //DRIVE_CURRENT      
    writeFDC(0x1F, 0x8C40);         //^      
    writeFDC(0x20, 0x8800);         //^      
    writeFDC(0x21, 0x8800);         //^      
    writeFDC(0x1A, 0x1E01);         //CONFIG      
}

void FDC::setupSensor(byte sensorNum, FDCSensor& sensor) {
    _sensors[sensorNum] = sensor;
}

// FDCSensor FDC::sensor(int num) {
    // return _sensors[num];
// }

int FDC::writeFDC(byte regAddr, unsigned int regVal) {
    Wire.beginTransmission(_I2C_Addr);
    Wire.write(regAddr);
    Wire.write(highByte(regVal));
    Wire.write(lowByte(regVal));
    return Wire.endTransmission();
}

unsigned int FDC::readFDC(byte regAddr) {
    Wire.beginTransmission(_I2C_Addr);
    Wire.write(regAddr);
    Wire.endTransmission();

    unsigned int reading = 0;
    Wire.requestFrom(_I2C_Addr, 2);
    if(Wire.available() >= 2) {
        reading = Wire.read();
        reading = reading << 8;
        reading |= Wire.read();
    }
    return reading;
}

unsigned int FDC::sensorRaw(byte sensorNum) {
    return readFDC(fetchDataAddress(sensorNum));
}

long FDC::sensorFreq(byte sensorNum, bool MHz) {
    if(MHz) {
        return _fRef * sensorRaw(sensorNum) / pow(2, 12) / pow(10, 6);
    }
    else {
        return _fRef * sensorRaw(sensorNum) / pow(2, 12);
    }
}

double FDC::sensorCap(byte sensorNum, bool pF) {
    if(pF) {
        return ((1 / (_sensors[sensorNum].tankInd() * pow(2 * PI * sensorFreq(sensorNum, false), 2))) - _sensors[sensorNum].tankCap()) * pow(10, 12);
    }
    else {
        return (1 / (_sensors[sensorNum].tankInd() * pow(2 * PI * sensorFreq(sensorNum, false), 2))) - _sensors[sensorNum].tankCap();
    }
}

unsigned int FDC::fetchDataAddress(byte sensorNum) {
    if(sensorNum == 0) {
        return 0x00;
    }
    else if(sensorNum == 1) {
        return 0x02;
    } 
    else if(sensorNum == 2) {
        return 0x04;
    }
    else if(sensorNum == 3) {
        return 0x06;
    }
    return 0;
}