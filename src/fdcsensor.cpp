#include <fdcsensor.h>

FDCSensor::FDCSensor(double capacitance, double inductance) :
    _tankCap(capacitance),
    _tankInd(inductance)
{
}

double FDCSensor::tankCap() {
    return _tankCap;
}

void FDCSensor::setTankCap(double capacitance) {
    _tankCap = capacitance;
}

double FDCSensor::tankInd() {
    return _tankInd;
}

void FDCSensor::setTankInd(double inductance) {
    _tankInd = inductance;
}