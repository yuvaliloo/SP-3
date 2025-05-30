#include "Player.hpp"
#include "Spy.hpp"
#include <iostream>

Spy::Spy(Game* game,const std::string& name)
    : Player(game,name) {}

std::string Spy::getRole() const {
    return "Spy";
}


void Spy::disableArrest(Player* target) {
    if (!target || !target->isCurrentlyActive()) {
        std::cout << "Invalid target for disableArrest.\n";
        return;
    }
    target->setCanArrest(false);
    std::cout << name << " disabled " << target->getName() << "'s ability to arrest next turn.\n";
}

void Spy::reveal(Player* target) {
    if (!target || !target->isCurrentlyActive()) {
        std::cout << "Invalid target for reveal.\n";
        return;
    }
    std::cout << name << " reveals that " << target->getName()
              << " has " << target->getCoinCount() << " coins.\n";
}
