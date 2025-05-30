#ifndef GENERAL_HPP
#define GENERAL_HPP

#include "Player.hpp"

class General : public Player {
public:
    General(Game* game,const std::string& name);
    std::string getRole() const override;

    void gather() override;  
    void tax() override;
    void bribe() override;
    void arrest(Player* target) override;
    void sanction(Player* target) override;
    void coup(Player* target) override;
    void blockCoup(Player* target);
};

#endif // GENERAL_HPP
