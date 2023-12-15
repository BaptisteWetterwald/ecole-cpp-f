//
// Created by Baptiste WETTERWALD on 14/12/2023.
//

#ifndef ECOLE_CPP_F_ENERGY_H
#define ECOLE_CPP_F_ENERGY_H


#include "card.h"

class EnergyCard : public Card {
public:
    EnergyCard(string energyType);
    void displayInfo() const override;

    string energyType;
};


#endif //ECOLE_CPP_F_ENERGY_H
