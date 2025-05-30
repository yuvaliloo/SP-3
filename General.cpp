#include "Player.hpp"
#include "General.hpp"
#include <iostream>

General::General(Game* game,const std::string& name)
    : Player(game,name) {}

std::string General::getRole() const {
    return "General";
}

void General::blockCoup(Player* target) {
    if (coins < 5) {
        throw std::runtime_error("Not enough coins to block coup");
    }

    decreaseCoins(5);
    target->setActive();  // Revives the player
    std::cout << name << " (General) blocked a coup against " << target->getName() << ".\n";
}
