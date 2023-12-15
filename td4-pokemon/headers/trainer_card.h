//
// Created by Baptiste WETTERWALD on 14/12/2023.
//

#ifndef ECOLE_CPP_F_TRAINER_CARD_H
#define ECOLE_CPP_F_TRAINER_CARD_H


#include "card.h"

class TrainerCard : public Card {
public:
    TrainerCard(string name, string trainerEffect);
    void displayInfo() const override;
    string trainerEffect;
};


#endif //ECOLE_CPP_F_TRAINER_CARD_H
