#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Game;

class Player {
protected:
    std::string name;
    int coins;
    bool active;
    Game* game;
    bool sanctioned;
    bool arrestedLast;
    bool canArrest;
    bool didBribe;
    bool bribeBlocked;

public:
    Player(Game* game, const std::string& name);
    virtual ~Player() = default;

    const std::string& getName() const;
    virtual std::string getRole() const = 0;

    int getCoinCount() const;
    void increaseCoins(int amount);
    void decreaseCoins(int amount);

    bool isCurrentlyActive() const;
    void setInactive();
    void setActive();

    bool isSanctioned() const;
    void setSanctionStatus(bool status);

    bool wasArrestedLastTurn() const;
    void setArrestedStatus(bool status);

    bool getCanArrest() const;
    void setCanArrest(bool status);

    bool getDidBribe() const;
    void setDidBribe(bool status);

    bool isBribeBlocked() const;
    void setBribeBlocked(bool status);

    Game* getGame() const;

    virtual void gather();
    virtual void tax();
    virtual void bribe();
    virtual void arrest(Player* target);
    virtual void sanction(Player* target);
    virtual void coup(Player* target);
};
#endif //PLAYER_HPP