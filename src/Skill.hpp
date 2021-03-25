#ifndef Skill_HPP
#define Skill_HPP
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "Element.hpp"
#include "SkillDatabase.hpp"
using namespace std;
class Skill : SkillDatabase {
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
        //Konstruktor Skill Random
        //Dapat men-generate random skill yang ada di database
        //Harus pake srand (time(NULL)) di main (waktu pertama kali program dijalanin)
        Skill();
        //Konstruktor Skill Unique
        //Masukkan nama spesies untuk menginstansiasi skill unique-nya
        Skill(string species);
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