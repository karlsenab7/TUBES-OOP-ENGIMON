#ifndef __BREED_HPP__
#define __BREED_HPP__

#include <iostream>
#include <vector>
#include "folderEngimon/Engimon.hpp"
//#include "Database.hpp"
#include "Element.hpp"
using namespace std;

class Breed
{
private:
    Engimon first;
    Engimon second;
    Engimon child;

    vector<Skill> inheritSkill();
    vector<Element> inheritElement(string&);
    vector<Element> getKombinasiElement(string&, Element, Element);
    void setChildSkill(vector<Skill>);
    void setChildElement(vector<string>);
    void sortSkill(vector<Skill>&);
    int isExistSkill(vector<Skill>, Skill);
    // int getElementAdvantage(string, string);

public:
    Breed(Engimon, Engimon, string);
    Breed(const Breed&);
    ~Breed();
    
    bool isValid();

    Engimon get_first();
    Engimon get_second();
    Engimon get_child();
    Engimon breed(string);

    void set_first(Engimon);
    void set_second(Engimon);
    void giveName(string);
    
    Engimon getNewEngimonFromDatabase(string, vector<Element>);
};

Breed::Breed(Engimon e1, Engimon e2, string name)
{
    this->first = e1;
    this->second = e2;

    this->child = breed(name);
}

Breed::Breed(const Breed& b)
{
    this->first = b.first;
    this->second = b.second;

    this->child = b.child;
}

Breed::~Breed()
{

}

Engimon Breed::get_first()
{
    return this->first;
}

Engimon Breed::get_second()
{
    return this->second;
}

Engimon Breed::get_child()
{
    return this->child;
}

void Breed::set_first(Engimon e)
{
    this->first = e;
}

void Breed::set_second(Engimon e)
{
    this->second = e;
}

bool Breed::isValid()
{
    return this->first.get_level() >= 30 && this->second.get_level() >= 30;
}

void Breed::giveName(string name)
{
    child.set_engimon_name(name);
}

vector<Skill> Breed::inheritSkill()
{
    vector<Skill> s1 = this->first.get_engimon_skill();
    vector<Skill> s2 = second.get_engimon_skill();
    vector<Skill> s;
    for (int i = 0; i < s1.size()+s2.size(); i++)
    {
        if (i >= s2.size())
            s.push_back(s1[i]);
        else
            s.push_back(s2[i]);
    }
    sortSkill(s);
    
    
    vector<Skill> inherit;
    
    int count = 0;
    while (count < 3 && !s1.empty() && !s2.empty() && count < s.size() && !s.empty())
    {
        Skill c = s.back();
        s.pop_back();

        int idx1 = isExistSkill(s1, c);
        int idx2 = isExistSkill(s2, c);
        int idx = isExistSkill(s, c);

        if (idx1 != -1 && idx2 != -1 && idx != -1)
        {
            if (s1[idx1].getMastery() == s2[idx2].getMastery())
            {
                c.setMastery(c.getMastery()+1);
            }
            else
            {
                if (s1[idx1].getMastery() > s1[idx2].getMastery())
                {
                    c = s1[idx1];
                }
                else
                {
                    c = s2[idx2];
                }
            }

            s1.erase(s1.begin()+idx1);
            s2.erase(s2.begin()+idx2);
            s.erase(s.begin()+idx);
        }
        else
        {
            if (idx1 != -1)
                s1.erase(s1.begin() + idx1);
            else if (idx2 != -1)
                s2.erase(s2.begin() + idx2);
        }

        inherit.push_back(c);
        count++;
    }
    
    return inherit;
}

vector<Element> Breed::inheritElement(string& species)
{
    vector<Element> els1 = first.get_engimon_elements();
    vector<Element> els2 = second.get_engimon_elements();

    vector<Element> inherit;

    if (els1.size() + els2.size() == 2)
    {
        Element el1 = els1[0];
        Element el2 = els2[0];

        inherit = getKombinasiElement(species, el1, el2);
    }
    else
    {
        Element el1 = els1[0];
        Element el2 = els2[0];
        
        inherit = getKombinasiElement(species, el1, el2);
    }


    return inherit;
}


vector<Element> Breed::getKombinasiElement(string& species, Element el1, Element el2)
{   
    vector<Element> inherit; 
    if (el1 == el2)
    {
        inherit.push_back(el1);
    }
    else
    {
        int n1 = el1.getAdvantage(el2);
        int n2 = el2.getAdvantage(el1);
        if (n1 == n1)
        {
            species = first.get_species_name();
            inherit.push_back(el1);
            inherit.push_back(el2);
        }
        else if (n1 > n2)
        {
            species = first.get_species_name();
            inherit.push_back(el1);
        }
        else
        {
            species = second.get_species_name();
            inherit.push_back(el2);
        }
        
    }

    return inherit;
}


Engimon Breed::breed(string name)
{
    vector<Skill> childSkill = inheritSkill();
    
    string species;
    vector<Element> childElement = inheritElement(species);

    Engimon e = getNewEngimonFromDatabase(species, childElement);

    for (int i = 0; i < childSkill.size(); i++)
        e.add_skill(childSkill[i]);
    
    e.set_engimon_name(name);

    // MENGURANGI LEVEL INDUK

    return e;
}


int Breed::isExistSkill(vector<Skill> s, Skill c)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i].getName() == c.getName())
            return i;
    }
    
    return -1;
}

void Breed::sortSkill(vector<Skill>& s)
{
    for (int i = 0; i < s.size()-1; i++)
    {
        int idxMin = i;
        for (int j = i+1; j < s.size(); j++)
        {
            if (s[idxMin].getMastery() > s[j].getMastery())
            {
                idxMin = j;
            }
        }

        Skill temp = s[i];
        s[i] = s[idxMin];
        s[idxMin] = temp;
    }
}

#endif