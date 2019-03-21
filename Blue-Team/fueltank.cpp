//
// Created by willf on 4/16/2018.
//

#include "fueltank.h"
#include <iostream>


fuelTank::fuelTank(){
    fuel = 100;
}

int fuelTank::getFuel() {
    return fuel;
}

void fuelTank::setFuel(int f) {
    fuel = f;
}

void fuelTank::useFuel() {
    if (fuel > 0) {
        fuel -= 5;
    }
}