#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include <memory>
#include "Player.hpp"

class Player; // Forward declaration

class Game {
private:
    std::vector<std::shared_ptr<Player>> players;
    size_t currentTurn;
    int coinBank;
    bool gameEnded;

public:
    Game();
    void addPlayer(const std::string& name, const std::string& role);
    std::string getCurrentPlayerName() const;
    std::vector<std::string> getActivePlayerNames() const;
    std::string getWinner() const;
    void advanceTurn();
    void removePlayerByName(const std::string& name);
    std::shared_ptr<Player> findPlayerByName(const std::string& name) const;
    int getCoinBank() const;
    void modifyCoinBank(int amount);
    bool isGameOver() const;
};

#endif // GAME_HPP