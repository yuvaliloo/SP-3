#include "Player.hpp"
#include "Baron.hpp"
#include <iostream>

Baron::Baron(Game* game,const std::string& name)
    : Player(game,name) {}

std::string Baron::getRole() const {
    return "Baron";
}

void Baron::invest() {
    if (coins < 3) {
        throw std::runtime_error("Not enough coins to invest");
    }
    decreaseCoins(3);
    increaseCoins(6);
    std::cout << name << " (Baron) invested 3 coins and gained 6. Total: " << coins << "\n";
}
