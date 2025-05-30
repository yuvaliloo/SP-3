// Player.cpp
#include "Player.hpp"
#include "Game.hpp"
#include <stdexcept>
#include <iostream>

Player::Player( Game* game, const std::string& name)
    : name(name), coins(0), active(true), game(game), sanctioned(false),
      arrestedLast(false), canArrest(true), didBribe(false), bribeBlocked(false) {}

const std::string& Player::getName() const {
    return name;
}

int Player::getCoinCount() const {
    return coins;
}

void Player::increaseCoins(int amount) {
    coins += amount;
}

void Player::decreaseCoins(int amount) {
    if (amount > coins) {
        throw std::runtime_error("Not enough coins");
    }
    coins -= amount;
}

bool Player::isCurrentlyActive() const {
    return active;
}

void Player::setInactive() {
    active = false;
}

void Player::setActive() {
    active = true;
}

bool Player::isSanctioned() const {
    return sanctioned;
}

void Player::setSanctionStatus(bool status) {
    sanctioned = status;
}

bool Player::wasArrestedLastTurn() const {
    return arrestedLast;
}

void Player::setArrestedStatus(bool status) {
    arrestedLast = status;
}

bool Player::getCanArrest() const {
    return canArrest;
}

void Player::setCanArrest(bool status) {
    canArrest = status;
}

bool Player::getDidBribe() const {
    return didBribe;
}

void Player::setDidBribe(bool status) {
    didBribe = status;
}

bool Player::isBribeBlocked() const {
    return bribeBlocked;
}

void Player::setBribeBlocked(bool status) {
    bribeBlocked = status;
}

Game* Player::getGame() const {
    return game;
}

// Default actions - can be overridden

void Player::gather() {
    if (sanctioned) {
        std::cout << name << " is sanctioned and cannot gather.\n";
        return;
    }
    increaseCoins(1);
    std::cout << name << " gathers and now has " << coins << " coins.\n";
}

void Player::tax() {
    if (sanctioned) {
        std::cout << name << " is sanctioned and cannot tax.\n";
        return;
    }
    increaseCoins(2);
    std::cout << name << " performs tax and now has " << coins << " coins.\n";
}

void Player::bribe() {
    if (coins < 4) {
        throw std::runtime_error("Not enough coins to bribe");
    }
    decreaseCoins(4);
    didBribe = true;
    std::cout << name << " bribed and can act again.\n";
}

void Player::arrest(Player* target) {
    if (!canArrest) {
        std::cout << name << " is unable to arrest this turn.\n";
        return;
    }

    if (coins < 1) {
        throw std::runtime_error("Not enough coins to arrest");
    }

    target->setArrestedStatus(true);

    if (target->getRole() == "Merchant") {
        game->modifyCoinBank(2);
        std::cout << name << " attempted to arrest " << target->getName()
                  << " (Merchant), who paid 2 coins to bank.\n";
    } 
    else if(target->getRole()=="General")
    {
        std::cout << name << " attempted to arrest " << target->getName()
                  << " (General), who cannot be arrested.\n";
    }
    else {
        increaseCoins(1);
        std::cout << name << " arrested " << target->getName() << " and gained 1 coin.\n";
    }
}

void Player::sanction(Player* target) {
    target->setSanctionStatus(true);

    if (target->getRole() == "Baron") {
        target->increaseCoins(1); // Baron compensation
        std::cout << target->getName() << " is a Baron and gets 1 coin as compensation.\n";
    }

    if (target->getRole() == "Judge") {
        decreaseCoins(1);
        game->modifyCoinBank(1);
        std::cout << "Sanctioning a Judge: " << name << " loses 1 extra coin to bank.\n";
    }

    std::cout << name << " sanctioned " << target->getName() << ".\n";
}

void Player::coup(Player* target) {
    if (coins < 7) {
        throw std::runtime_error("Not enough coins to perform coup");
    }

    decreaseCoins(7);
    target->setInactive();
    std::cout << name << " performed coup on " << target->getName() << ".\n";
}
