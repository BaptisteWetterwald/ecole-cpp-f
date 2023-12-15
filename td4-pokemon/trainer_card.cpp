//
// Created by Baptiste WETTERWALD on 14/12/2023.
//

#include <iostream>
#include "headers/trainer_card.h"

TrainerCard::TrainerCard(string name, string trainerEffect) : Card(name) {
    this->trainerEffect = trainerEffect;
}

void TrainerCard::displayInfo() const {
    cout << "Trainer Card - Name : " << cardName << ", Effect : " << trainerEffect << endl;
}
