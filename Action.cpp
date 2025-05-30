#include "Action.hpp"
#include "Game.hpp"
#include <stdexcept>

void Action::gather(Player* player) {
    if (player->isSanctioned()) throw std::runtime_error("Sanctioned players can't gather");
    player->getGame()->modifyCoinBank(-1);
    player->increaseCoins(1);
}

void Action::tax(Player* player) {
    if (player->isSanctioned()) throw std::runtime_error("Sanctioned players can't tax");
    int amount = (player->getRole() == "Governor") ? 3 : 2;
    player->getGame()->modifyCoinBank(-amount);
    player->increaseCoins(amount);
}

void Action::bribe(Player* player) {
    player->decreaseCoins(4);
    // Bribe allows an extra turn - you may integrate it with game loop
}

void Action::arrest(Player* source, Player* target) {
    if (target->wasArrestedLastTurn()) throw std::runtime_error("Player was arrested last turn");
    if (target->getCoinCount() < 1) throw std::runtime_error("Target has no coins");

    target->decreaseCoins(1);
    source->increaseCoins(1);

    target->setArrestedStatus(true);
}

void Action::sanction(Player* source, Player* target) {
    source->decreaseCoins(3);
    target->setSanctionStatus(true);
}

void Action::coup(Player* source, Player* target) {
    if (source->getCoinCount() < 7) throw std::runtime_error("Not enough coins for coup");
    source->decreaseCoins(7);
    target->setInactive();
}