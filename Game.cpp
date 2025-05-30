#include "Game.hpp"
#include "Player.hpp"
#include "Governor.hpp"
#include "General.hpp"
#include "Spy.hpp"
#include "Merchant.hpp"
#include "Judge.hpp"
#include "Baron.hpp"
#include <stdexcept>

Game::Game() : currentTurn(0), coinBank(50), gameEnded(false) {}

void Game::addPlayer(const std::string& name, const std::string& role) {
    std::shared_ptr<Player> newPlayer;

    if (role == "Governor") {
        newPlayer = std::make_shared<Governor,Game*, const std::string&>(this,name);
    } else if (role == "Spy") {
        newPlayer = std::make_shared<Spy,Game*, const std::string&>(this,name);
    } else if (role == "Baron") {
        newPlayer = std::make_shared<Baron,Game*, const std::string&>(this,name);
    } else if (role == "General") {
        newPlayer = std::make_shared<General,Game*, const std::string&>(this,name);
    } else if (role == "Judge") {
        newPlayer = std::make_shared<Judge,Game*, const std::string&>(this,name);
    } else if (role == "Merchant") {
        newPlayer = std::make_shared<Merchant,Game*, const std::string&>(this,name);
    } else {
        // Handle unknown role — you can throw, log, or ignore
        throw std::invalid_argument("Unknown player role: " + role);
        // Or simply return to ignore adding:
        // return;
    }

    players.push_back(newPlayer);
}

std::string Game::getCurrentPlayerName() const {
    if (players.empty()) throw std::runtime_error("No players in game");
    return players.at(currentTurn)->getName();
}

std::vector<std::string> Game::getActivePlayerNames() const {
    std::vector<std::string> names;
    for (const auto& player : players) {
        if (player->isCurrentlyActive()) {
            names.push_back(player->getName());
        }
    }
    return names;
}

std::string Game::getWinner() const {
    if (!gameEnded) throw std::runtime_error("Game is still ongoing");
    for (const auto& player : players) {
        if (player->isCurrentlyActive()) return player->getName();
    }
    throw std::runtime_error("No active player found");
}

void Game::advanceTurn() {
    if (gameEnded) return;
    size_t count = 0;
    do {
        currentTurn = (currentTurn + 1) % players.size();
        count++;
    } while (!players[currentTurn]->isCurrentlyActive() && count < players.size());

    int activeCount = 0;
    for (const auto& player : players) {
        if (player->isCurrentlyActive()) activeCount++;
    }
    if (activeCount == 1) gameEnded = true;
}

void Game::removePlayerByName(const std::string& name) {
    auto player = findPlayerByName(name);
    if (player) player->setInactive();
}

std::shared_ptr<Player> Game::findPlayerByName(const std::string& name) const {
    for (const auto& player : players) {
        if (player->getName() == name) return player;
    }
    throw std::runtime_error("Player not found: " + name);
}

int Game::getCoinBank() const {
    return coinBank;
}

void Game::modifyCoinBank(int amount) {
    if (coinBank + amount < 0) throw std::runtime_error("Bank has insufficient coins");
    coinBank += amount;
}

bool Game::isGameOver() const {
    return gameEnded;
}