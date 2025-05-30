#include "Player.hpp"
#include "Merchant.hpp"
#include <iostream>

Merchant::Merchant(Game* game,const std::string& name): Player(game, name) {}
Merchant::Merchant(const std::string& name,Game* game): Player(game, name) {}

std::string Merchant::getRole() const {
    return "Merchant";
}

void Merchant::onTurnStart() {
    if (coins >= 3) {
        increaseCoins(1);
        std::cout << name << " (Merchant) started turn with 3+ coins and gained 1 extra coin. Now has " << coins << ".\n";
    }
}
