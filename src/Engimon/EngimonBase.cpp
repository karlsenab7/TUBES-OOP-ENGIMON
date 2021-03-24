// Implementasi perlu dipisah dari header karena ada variabel static sebagai id engimon
#include <vector>
#include <iostream>
#include "EngimonBase.hpp"

using namespace std;

//Static var
int EngimonBase::numOfCreated = 1;

//Constructor
EngimonBase::EngimonBase() : engimon_id(numOfCreated)
{
    engimon_name = "-";
    level = 0;
    exp = 0;
    cum_exp = 0;

    engimon_elements.assign(2, "none");

    engimon_parents = new string [2];
    for (int i = 0; i < 2; i++) {engimon_parents[i] = "-";}

    numOfCreated += 1;
}

EngimonBase::EngimonBase(string name, string * parents, vector<string> elements, int _level, int _exp, int _cum_exp) : engimon_id(numOfCreated)
{
    engimon_name = name;
    level = _level;
    exp = _exp;
    cum_exp = _cum_exp;

    engimon_elements = elements;

    engimon_parents = new string [2];
    for (int i = 0; i < 2; i++) {engimon_parents[i] = parents[i];}

    numOfCreated += 1;
}

EngimonBase::EngimonBase(const EngimonBase& other) : engimon_id(numOfCreated)
{
    EngimonBase(other.engimon_name, other.engimon_parents, other.engimon_elements, other.level, other.exp, other.cum_exp);
}

//Destructor
EngimonBase::~EngimonBase() {
    delete[] engimon_parents;
    //~engimon_elements;
}

//Getter
int EngimonBase::get_engimon_id() { return engimon_id; }
string EngimonBase::get_engimon_name() { return engimon_name; }
string * EngimonBase::get_engimon_parents() { return engimon_parents; }  
vector<string> EngimonBase::get_engimon_elements() { return engimon_elements; }
int EngimonBase::get_level() { return level; }
int EngimonBase::get_exp() { return exp; }
int EngimonBase::get_cum_exp() { return cum_exp; }

//Setter
void EngimonBase::set_engimon_name(string name) { engimon_name = name; }
void EngimonBase::set_engimon_parents(string * parents) {
    for(int i = 0; i < 2; i++) { engimon_parents[i] = parents[i]; }
}
void EngimonBase::set_engimon_elements(vector<string> elements) { engimon_elements = elements; };
void EngimonBase::set_level(int _level) { level = _level; }
void EngimonBase::set_exp(int _exp) { exp = _exp; }
void EngimonBase::set_cum_exp(int _cum_exp) { cum_exp = _cum_exp; }

//Additional Methods
void EngimonBase::add_exp(int add) {
    cum_exp += add;
    exp += add;
    if (exp > 100) {
        level += 1;
        exp -= 100;
    }
}