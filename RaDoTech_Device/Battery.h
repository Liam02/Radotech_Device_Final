#ifndef BATTERY_H
#define BATTERY_H

#include <string>
#include <iostream>

using namespace std;

class Battery{

public:
    Battery();
    void depleteBattery();
    string lowBatteryWarning();
    bool checkLowBattery();
    void recharge();

    int getBattery();


private:
    int currentBattery;
    bool lowBattery;
};

#endif // BATTERY_H
