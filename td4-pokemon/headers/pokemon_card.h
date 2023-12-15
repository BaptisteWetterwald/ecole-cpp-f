//
// Created by Baptiste WETTERWALD on 14/12/2023.
//

#ifndef ECOLE_CPP_F_POKEMON_CARD_H
#define ECOLE_CPP_F_POKEMON_CARD_H


#include <vector>
#include "card.h"

class PokemonCard : public Card {
public:
    PokemonCard(string cardName, string pokemonType, string familyName, int evolutionLevel, int maxHP, int costAttack1, string descriptionAttack1, int damageAttack1, int costAttack2, string descriptionAttack2, int damageAttack2);
    void displayInfo() const override;
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<tuple<int, int, string, int>> attacks; // cost, actual cost, description, damage
};


#endif //ECOLE_CPP_F_POKEMON_CARD_H
