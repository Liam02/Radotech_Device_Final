#include "ui_HomeScreenPage.h"
#include "Battery.h"

Battery::Battery(){
    currentBattery = 100;
    lowBattery = false;
}

void Battery:: depleteBattery(){
    currentBattery -= 10;
    if(currentBattery <= 20){
        lowBattery = true;
    }
}

int Battery::getBattery(){
    return currentBattery;
}

bool Battery::checkLowBattery(){
    if(currentBattery <= 20){
        lowBattery = true;
        return lowBattery;
    }
    return lowBattery;
}

void Battery::recharge(){
    currentBattery = 100;
    lowBattery = false;
}

string Battery::lowBatteryWarning(){
    return "Warning! Battery is low!";
}
