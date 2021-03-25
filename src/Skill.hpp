#ifndef Skill_HPP
#define Skill_HPP
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Repo/src/Element.hpp"
using namespace std;
class Skill {
    private:
        string ID;
        string name;
        vector<Element> element;
        int power;
        int mastery;
        string description;
        bool isUnique;
        string uniqueTo;
    public:
        //Konstruktor
        Skill(string ID, string name, vector<Element> element, int power, string desc, bool isUnique, string uniqueTo);
        //CC
        Skill(const Skill& s);
        //OpAssign
        Skill& operator=(const Skill& s);
        // getter
        string getID();
        string getName();
        vector<Element> getElement();
        int getPower();
        int getMastery();
        string getDescription();
        // Lain-Lain
        void masteryUp();
        bool canBeLearned(Element element);
        void print();
};
#endif