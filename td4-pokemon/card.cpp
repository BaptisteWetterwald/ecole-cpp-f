//
// Created by Baptiste WETTERWALD on 14/12/2023.
//

#include "headers/card.h"

string Card::getName() const {
    return cardName;
}

Card::Card(string name) {
    this->cardName = name;
}
