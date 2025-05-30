#ifndef MERCHANT_HPP
#define MERCHANT_HPP

#include "Player.hpp"

class Merchant : public Player {
public:

    Merchant(Game* game, const std::string& name);
    Merchant(const std::string& name,Game* game);
    std::string getRole() const override;

    void gather() override;  
    void tax() override;
    void bribe() override;
    void arrest(Player* target) override;
    void sanction(Player* target) override;
    void coup(Player* target) override;
    void onTurnStart();
};

#endif // MERCHANT_HPP
