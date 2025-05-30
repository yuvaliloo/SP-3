#ifndef ACTION_HPP
#define ACTION_HPP

#include "Player.hpp"

class Action {
public:
    static void gather(Player* player);
    static void tax(Player* player);
    static void bribe(Player* player);
    static void arrest(Player* source, Player* target);
    static void sanction(Player* source, Player* target);
    static void coup(Player* source, Player* target);
};

#endif // ACTION_HPP