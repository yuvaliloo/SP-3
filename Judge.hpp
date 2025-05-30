#ifndef JUDGE_HPP
#define JUDGE_HPP

#include "Player.hpp"

class Judge : public Player {
public:
    Judge(Game* game, const std::string& name);
    std::string getRole() const override;

    void gather() override;  
    void tax() override;
    void bribe() override;
    void arrest(Player* target) override;
    void sanction(Player* target) override;
    void coup(Player* target) override;
    void blockBribe(Player* target);
};

#endif // JUDGE_HPP
