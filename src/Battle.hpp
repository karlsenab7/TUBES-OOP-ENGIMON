#ifndef __BATTLE_HPP__
#define __BATTLE_HPP__

#include <iostream>
#include <vector>
#include "Engimon.hpp"
// #include "EngimonBase.hpp"
#include "Element.hpp"
#include "Skill.hpp"
#include "Inventory.hpp"

using namespace std;

class Battle
{
private:
    Engimon first;
    Engimon second;
    Inventory<Engimon> inventoryEngimon;
    Inventory<Skill> inventorySkill;


public:
    Battle(Engimon, Engimon, Inventory<Engimon>&, Inventory<Skill>&);
    ~Battle();

    // getter
    Engimon get_first();
    Engimon get_second();

    // setter
    void set_first(Engimon);
    void set_second(Engimon);

    //Method
    float type_adv(Element, Element);
    float sum_power(Engimon, vector<Element>);
    void fight();
    void win();
    void lose();
    void get_reward();
    void get_penalty();
};

Battle::Battle(Engimon e1, Engimon e2, Inventory<Engimon> &inventoryEngimon, Inventory<Skill> &inventorySKill)
{
    this->first = e1;
    this->second = e2;
    this->inventoryEngimon = inventoryEngimon;
    this->inventorySkill = inventorySkill;
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
    return el1.getAdvantage(el2);
}

float Battle::sum_power(Engimon e1, vector <Element> els2) //Menunggu class skill
{
    int l1 = e1.get_level();
    vector <Element> els1 = e1.get_engimon_elements();
    float maks = type_adv(els1[0], els2[0]);
    for (int i = 0; i < els1.size(); i++)
    {
        for (int j = 0; j < els2.size(); j++)
        {
            float maks_tmp = type_adv(els1[i], els2[j]);
            if (maks_tmp > maks)
            {
                maks = maks_tmp;
            }
        }
    }
    int sum = e1.get_total_skill_power();
    int sp = l1 * maks + sum;
    return sp;

}

void Battle::fight()
{
    float fp1 = sum_power(first, second.get_engimon_elements());
    float fp2 = sum_power(second, first.get_engimon_elements());
    //Memberi interface ke user
    if (fp1 > fp2)
    {
        win();
    }
    else
    {
        lose();
    }
}

void Battle::win()
{
    //Menampilkan interface
    get_reward();
}

void Battle::lose()
{
    //Menampilkan interface
    get_penalty();
}

void Battle::get_reward()
{
    Skill e;
}

void Battle::get_penalty()
{

}
#endif