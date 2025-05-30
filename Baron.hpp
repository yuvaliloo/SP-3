#ifndef BARON_HPP
#define BARON_HPP

#include "Player.hpp"

class Baron : public Player {
public:
    Baron(Game* game,const std::string& name);
    std::string getRole() const override;

    void gather() override;  
    void tax() override;
    void bribe() override;
    void arrest(Player* target) override;
    void sanction(Player* target) override;
    void coup(Player* target) override;
    void invest();
};

#endif // BARON_HPP
