/**
 *  @class  FDC
 *  @author Jacob White
 *  
 *  @description    This class is to help streamline the use of Texas-Instruments FDC2114 sensor
 *  
 *  @methods
 *
 *      FDC(bool ADDR_pin_H, long refFrequency)
 *          DESCRIPTION - constructor for fdc class
 *          OPTIONAL    - if ADDR_pin_H is true changes the I2C address accordingly.
 *                          refFrequency sets the refernce frequency for calculation 
 *                          of sensor frequency and capacitance
 *
 *      INIT(bool sensor2, bool sensor2_3)
 *          DESCRIPTION - initializees
 *          PRE         - call after Wire.begin() has been called
 *          POST        - configures control registers and takes device out of sleepmode
 *          OPTIONAL    - sensor2, and sensor2_3 enable the use of CH2 and CH2 & CH3 respectively. 
 *                           If sensor2_3 is true, sensor2 is ignored  
 *
 *      setupSensor(int sensorNum, FDC::Sensor sensor)
 *          DESCRIPTION - configures the capacitance and inductance for the sensor attached 
 *                          to a respective channel #
 *          PRE         - sensorNum MUST be between 0->3
 *          POST        - adds given sensor struct to _sensors[] field at location specified by sensorNum
 *
 *      writeFDC(byte regAddr, unsigned int regVal)
 *          DESCRIPTION - writes 2 bytes to the specified address
 *          RETURNS     - (optional) error code for the state of transmission 
 *
 *      readFDC(byte regAddr)
 *          DESCRIPTION - read 2 bytes from the specified register
 *          RETURNS     - unsigned int (2 bytes) from the specified address
 *
 *      sensorRaw(int sensorNum)
 *          PRE         - sensorNum MUST be between 0->3
 *          RETURNS     - 2 bytes from the specified sensor's data register. No alterations
 *  
 *      sensorFreq(int sensorNum, bool MHz)
 *          PRE         - sensorNum MUST be between 0->3
 *          RETURNS     - the frequency of oscillation for the specified sensor in MHz
 *          OPTIONAL    - if MHz is true, returns result in MHz
 *
 *      sensorCap(int sensorNum, bool pF)
 *          PRE         - sensorNum MUST be between 0->3
 *          RETURNS     - the capacitance on the specified sensor in F
 *          OPTIONAL    - if pF is true, returns result in pF
 *
 *      unsigned int fetchDataAddress(int sensorNum)
 *          DESCRIPTION - helper function to supply data address' for data aquisition functions
 *          PRE         - sensorNum MUST be between 0->3
 *          RETURNS     - the register address for the specific sensor channel
 */