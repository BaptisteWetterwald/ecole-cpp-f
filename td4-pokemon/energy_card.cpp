//
// Created by Baptiste WETTERWALD on 14/12/2023.
//

#include "headers/energy_card.h"
#include <string>
#include <iostream>

using namespace std;

EnergyCard::EnergyCard(string energyType) : Card("Energy") {
    this->energyType = energyType;
}

void EnergyCard::displayInfo() const {
    cout << "Energy Card: " << cardName << " (" << energyType << ")" << endl;
}