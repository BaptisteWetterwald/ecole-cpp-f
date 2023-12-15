//
// Created by Baptiste WETTERWALD on 14/12/2023.
//

#ifndef ECOLE_CPP_F_CARD_H
#define ECOLE_CPP_F_CARD_H


#include <string>
using namespace std;

class Card {
public:
    Card(string name);
    virtual void displayInfo() const = 0;
    [[nodiscard]] string getName() const;

protected:
    string cardName;
};


#endif //ECOLE_CPP_F_CARD_H
