//
// Created by Baptiste WETTERWALD on 14/12/2023.
//

#ifndef ECOLE_CPP_F_PLAYER_H
#define ECOLE_CPP_F_PLAYER_H

#include <string>
#include "card.h"
#include "pokemon_card.h"

class Player {
public:
    Player(string playerName);
    void addCardToBench(Card* card);
    void activatePokemonCard(int index);
    void attachEnergyCard(int indexPokemon, int indexEnergy);
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;
    void displayBench() const;
    void displayAction() const;
    void attack(int indexPokemon, int indexAttack, Player player, int indexOtherPokemon);
    void useTrainer(int indexBench);
};

#endif //ECOLE_CPP_F_PLAYER_H
