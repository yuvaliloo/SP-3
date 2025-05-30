#ifndef GOVERNOR_HPP
#define GOVERNOR_HPP

#include "Player.hpp"

class Governor : public Player {
public:
    Governor( Game* game,const std::string& name);
    std::string getRole() const override;

    void gather() override;  
    void tax() override;
    void bribe() override;
    void arrest(Player* target) override;
    void sanction(Player* target) override;
    void coup(Player* target) override;
    void blockTax(Player* target);
};

#endif // GOVERNOR_HPP
