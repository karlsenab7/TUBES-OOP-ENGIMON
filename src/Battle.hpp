#ifndef __BATTLE_HPP__
#define __BATTLE_HPP__

#include "Engimon/Engimon.hpp"
class Battle
{
private:
    Engimon first;
    Engimon second;

public:
    Battle(/* args */);
    ~Battle();
    float type_adv();
    float sum_power();
    void fight();
    void win();
    void lose();
    void get_reward();
};

Battle::Battle(/* args */)
{
}

Battle::~Battle()
{
}

#endif