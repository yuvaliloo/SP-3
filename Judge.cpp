#include "Player.hpp"
#include "Judge.hpp"
#include <iostream>

Judge::Judge(Game* game, const std::string& name)
    : Player(game,name) {}

std::string Judge::getRole() const {
    return "Judge";
}

void Judge::blockBribe(Player* target) {
    target->setBribeBlocked(true);
    std::cout << name << " (Judge) blocked " << target->getName() << "'s bribe.\n";
}
