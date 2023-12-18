//
// Created by Baptiste WETTERWALD on 14/12/2023.
//
#include <iostream>
#include <stdexcept>

#include "headers/player.h"
#include "headers/energy_card.h"
#include "headers/trainer_card.h"

using namespace std;

Player::Player(string playerName) {
    this->playerName = playerName;
    this->benchCards = vector<Card*>();
    this->actionCards = vector<PokemonCard*>();
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index) {

    if (index >= benchCards.size()) {
        throw out_of_range("Pokemon index out of range");
    }
    if (dynamic_cast<PokemonCard*>(benchCards[index]) == nullptr) {
        throw invalid_argument("Card is not a Pokemon Card");
    }

    cout
        << this->playerName
        << " is activating a Pokemon Card: "
        << benchCards[index]->getName() << endl;

    actionCards.push_back((PokemonCard*) benchCards[index]);
    benchCards.erase(benchCards.begin() + index);
}

void Player::attachEnergyCard(int indexPokemon, int indexEnergy) {

    if (indexPokemon >= actionCards.size()) {
        throw out_of_range("Pokemon index out of range");
    }
    if (indexEnergy >= benchCards.size()) {
        throw out_of_range("Energy index out of range");
    }
    if (benchCards[indexEnergy]->getName() != "Energy") {
        throw invalid_argument("Card is not an Energy Card");
    }
    if (dynamic_cast<PokemonCard*>(actionCards[indexPokemon]) == nullptr) {
        throw invalid_argument("Card is not a Pokemon Card");
    }

    cout
        << this->playerName
        << " is attaching an Energy Card of type "
        << dynamic_cast<EnergyCard*>(benchCards[indexEnergy])->energyType
        << " to the Pokemon "
        << actionCards[indexPokemon]->getName() << endl;

    auto attacks = actionCards[indexPokemon]->attacks;
    for (int i = (int)attacks->size() - 1; i >= 0; i--) {
        tuple<int, int, string, int> newAttack = make_tuple(
            get<0>(attacks->at(i)),
            get<1>(attacks->at(i)) + 1,
            get<2>(attacks->at(i)),
            get<3>(attacks->at(i))
        );
        attacks->erase(attacks->begin() + i);
        attacks->insert(attacks->begin() + i, newAttack);
        cout << "Attack " << get<2>(newAttack) << " now has " << get<1>(newAttack) << " energy" << endl;
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

    if (indexPokemon >= actionCards.size()) {
        throw out_of_range("Pokemon index out of range");
    }
    if (indexOtherPokemon >= player.actionCards.size()) {
        throw out_of_range("Other Pokemon index out of range");
    }
    if (indexAttack >= actionCards[indexPokemon]->attacks->size()) {
        throw out_of_range("Attack index out of range");
    }

    if (get<1>(actionCards[indexPokemon]->attacks->at(indexAttack)) < get<0>(actionCards[indexPokemon]->attacks->at(indexAttack))) {
        throw runtime_error("Not enough energy to perform this attack " + to_string(get<1>(actionCards[indexPokemon]->attacks->at(indexAttack))) + " " + to_string(get<0>(actionCards[indexPokemon]->attacks->at(indexAttack))));
    }

    // remove energy
    get<1>(actionCards[indexPokemon]->attacks->at(indexAttack)) -= get<0>(actionCards[indexPokemon]->attacks->at(indexAttack));

    cout
        << this->playerName
        << " attacking "
        << player.playerName << "'s Pokemon "
        << player.actionCards[indexOtherPokemon]->getName()
        << " with the Pokemon " << actionCards[indexPokemon]->getName()
        << " with its attack : " << get<2>(actionCards[indexPokemon]->attacks->at(indexAttack)) << endl;

    cout
        << "Reducing " << get<3>(actionCards[indexPokemon]->attacks->at(indexAttack))
        << " from " << player.playerName << "'s Pokemon "
        << player.actionCards[indexOtherPokemon]->getName() << "'s HP" << endl;

    player.actionCards[indexOtherPokemon]->hp -= get<3>(actionCards[indexPokemon]->attacks->at(indexAttack));

    if (player.actionCards[indexOtherPokemon]->hp <= 0) {
        cout << "Pokemon " << player.actionCards[indexOtherPokemon]->getName() << " is dead" << endl;
        player.actionCards.erase(player.actionCards.begin() + indexOtherPokemon);
    } else {
        cout << "Pokemon " << player.actionCards[indexOtherPokemon]->getName() << " is still alive" << endl;
    }
}

void Player::useTrainer(int indexBench) {

    if (indexBench >= benchCards.size()) {
        throw out_of_range("Trainer index out of range");
    }
    if (dynamic_cast<TrainerCard*>(benchCards[indexBench]) == nullptr) {
        throw invalid_argument("Card is not a Trainer Card");
    }

    string trainerEffect = ((TrainerCard*) benchCards[indexBench])->trainerEffect;

    cout
        << this->playerName
        << " is using the Trainer Card to \""
        << trainerEffect << "\"" << endl;

    if (trainerEffect == "heal all your action pokemon") {
        for (auto &actionCard : actionCards) {
            actionCard->hp = actionCard->maxHP;
        }
    }
    else {
        throw invalid_argument("Unknown Trainer Effect");
    }
}
