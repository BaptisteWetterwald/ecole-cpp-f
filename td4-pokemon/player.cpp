//
// Created by Baptiste WETTERWALD on 14/12/2023.
//
#include <iostream>
#include "headers/player.h"
#include "headers/energy_card.h"
#include "headers/trainer_card.h"

using namespace std;

Player::Player(string playerName) {
    this->playerName = playerName;
}

void Player::addCardToBench(Card *card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index) {
    cout << this->playerName << " is activating a Pokemon Card: " << benchCards[index]->getName() << endl;
    actionCards.push_back((PokemonCard*) benchCards[index]);
    benchCards.erase(benchCards.begin() + index);
}

void Player::attachEnergyCard(int indexPokemon, int indexEnergy) {
    cout << this->playerName << " is attaching an Energy Card of type " << dynamic_cast<EnergyCard*>(benchCards[indexEnergy])->energyType << " to the Pokemon " << actionCards[indexPokemon]->getName() << endl;
    auto attacks = actionCards[indexPokemon]->attacks;
    for (auto &attack : attacks) {
        get<1>(attack) += 1;
    }
    benchCards.erase(benchCards.begin() + indexEnergy);
}

void Player::displayBench() const {
    cout << "Bench cards for Player " << playerName << ":" << endl;
    for (auto &benchCard : benchCards) {
        benchCard->displayInfo();
    }
}

void Player::displayAction() const {
    cout << "Action cards for Player " << playerName << ":" << endl;
    for (auto &actionCard : actionCards) {
        actionCard->displayInfo();
    }
}

void Player::attack(int indexPokemon, int indexAttack, Player player, int indexOtherPokemon) {
    cout << this->playerName << " attacking " << player.playerName << "'s Pokemon " << player.actionCards[indexOtherPokemon]->getName() << " with the Pokemon " << actionCards[indexPokemon]->getName() << " with its attack : " << get<2>(actionCards[indexPokemon]->attacks[indexAttack]) << endl;
    cout << "Reducing " << get<3>(actionCards[indexPokemon]->attacks[indexAttack]) << " from " << player.playerName << "'s Pokemon " << player.actionCards[indexOtherPokemon]->getName() << "'s HP" << endl;
    player.actionCards[indexOtherPokemon]->hp -= get<3>(actionCards[indexPokemon]->attacks[indexAttack]);
    if (player.actionCards[indexOtherPokemon]->hp <= 0) {
        cout << "Pokemon " << player.actionCards[indexOtherPokemon]->getName() << " is dead" << endl;
        player.actionCards.erase(player.actionCards.begin() + indexOtherPokemon);
    } else {
        cout << "Pokemon " << player.actionCards[indexOtherPokemon]->getName() << " is still alive" << endl;
    }
}

void Player::useTrainer(int indexBench) {
    string trainerEffect = ((TrainerCard*) benchCards[indexBench])->trainerEffect;
    cout << this->playerName << " is using the Trainer Card to \"" << trainerEffect << "\"" << endl;
    if (trainerEffect == "heal all your action pokemon") {
        for (auto &actionCard : actionCards) {
            actionCard->hp = actionCard->maxHP;
        }
    }
    else {
        cout << "Unknown effect" << endl;
    }
}
