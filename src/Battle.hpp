#ifndef __BATTLE_HPP__
#define __BATTLE_HPP__

#include "Engimon.hpp"
#include "Element.hpp"
class Battle
{
private:
    Engimon first;
    Engimon second;

public:
    Battle();
    ~Battle();

    // getter
    Engimon get_first();
    Engimon get_second();

    // setter
    void set_first(Engimon);
    void set_second(Engimon);

    //Method
    float type_adv(Element, Element);
    float sum_power();
    void fight();
    void win();
    void lose();
    void get_reward();
};

Battle::Battle()
{

}

Battle::~Battle()
{
}

Engimon Battle:: get_first()
{
    return this->first;
}

Engimon Battle:: get_second()
{
    return this->second;
}

void Battle::set_first(Engimon e)
{
    this->first = e;
}

void Battle::set_second(Engimon e)
{
    this->second = e;
}

float Battle::type_adv(Element el1, Element el2)
{
    if (el1 == el2)
    {
        return 1;
    }
    else
    {
        int n1 = el1.getAdvantage(el2);
        int n2 = el2.getAdvantage(el1);
        return n1;
    }
}

float Battle::sum_power()
{

}

void Battle::fight()
{

}
void Battle::win()
{

}
void Battle::lose()
{

}
void Battle::get_reward()
{

}
#endif