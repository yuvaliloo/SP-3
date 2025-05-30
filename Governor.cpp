#include "Player.hpp"
#include "Game.hpp"
#include "Governor.hpp"
#include <iostream>

Governor::Governor(Game* game,const std::string& name)
    : Player(game,name) {}

std::string Governor::getRole() const {
    return "Governor";
}

void Governor::tax() {
    if (sanctioned) {
        std::cout << name << " is sanctioned and cannot tax.\n";
        return;
    }
    increaseCoins(3);  // Governor takes 3 instead of 2
    std::cout << name << " (Governor) taxed and now has " << coins << " coins.\n";
}

void Governor::blockTax(Player* target) {
    if (target == nullptr) {
        std::cerr << "Governor tried to block tax on a null target.\n";
        return;
    }

    // Assume the target just taxed and got 2 coins
    if (target->getCoinCount() >= 2) {
        target->decreaseCoins(2);
        target->getGame()->modifyCoinBank(2);
        std::cout << name << " (Governor) blocked " << target->getName()
                  << "'s tax. 2 coins returned to the bank.\n";
    } else {
        std::cout << "Cannot block tax: " << target->getName()
                  << " has less than 2 coins.\n";
    }
}
