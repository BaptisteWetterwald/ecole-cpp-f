//
// Created by Baptiste WETTERWALD on 14/12/2023.
//

#include "headers/pokemon_card.h"
#include <string>
#include <iostream>

PokemonCard::PokemonCard(string cardName, string pokemonType, string familyName, int evolutionLevel, int maxHP,
                         int costAttack1, string descriptionAttack1, int damageAttack1, int costAttack2,
                         string descriptionAttack2, int damageAttack2) : Card(cardName) {
    this->pokemonType = pokemonType;
    this->familyName = familyName;
    this->evolutionLevel = evolutionLevel;
    this->maxHP = maxHP;
    this->hp = maxHP;
    this->attacks = new vector<tuple<int, int, string, int>>();
    this->attacks->emplace_back(costAttack1, 0, descriptionAttack1, damageAttack1);
    this->attacks->emplace_back(costAttack2, 0, descriptionAttack2, damageAttack2);
}

void PokemonCard::displayInfo() const {
    cout << "Pokemon Card - Name : " << cardName << ", Type: " << pokemonType << ", Evolution Level: " << evolutionLevel << " of the family \"" << familyName << "\", HP: " << hp << endl;
    cout << "Attacks:" << endl;
    for (int i = 0; i < attacks->size(); i++) {
        cout << "Attack #" << i << ":" << endl;
        cout << "Attack cost: " << get<0>(attacks->at(i)) << endl;
        cout << "Attack current energy storage: " << get<1>(attacks->at(i)) << endl;
        cout << "Attack description: " << get<2>(attacks->at(i)) << endl;
        cout << "Attack damage: " << get<3>(attacks->at(i)) << endl;
    }
}
