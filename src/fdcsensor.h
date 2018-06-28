#ifndef FDCSENSOR_H
#define FDCSENSOR_H

class FDCSensor
{
public:
    FDCSensor(double capacitance = 0, double inductance = 0);

    double tankCap();
    void setTankCap(double capacitance);

    double tankInd();
    void setTankInd(double inductance);

private:
    double _tankCap;
    double _tankInd;
};

#endif  // FDCSENSOR_H