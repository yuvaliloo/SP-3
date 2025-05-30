#ifndef SPY_HPP
#define SPY_HPP

#include "Player.hpp"

class Spy : public Player {
public:
    Spy(Game* game,const std::string& name);
    std::string getRole() const override;

    void gather() override;  
    void tax() override;
    void bribe() override;
    void arrest(Player* target) override;
    void sanction(Player* target) override;
    void coup(Player* target) override;
    void disableArrest(Player* target);
    void reveal(Player* target);
};

#endif // SPY_HPP
