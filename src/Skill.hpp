#ifndef Skill_HPP
#define Skill_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Skill {
    private:
        string ID;
        string name;
        string element;
        int* learnableBy; 
        int power;
        int mastery;
        string description;
        bool isUnique;
        string uniqueTo;
    public:
        //Konstruktor
        Skill(string ID, string name, string element, int* learnableBy, int power, string desc, bool isUnique, string uniqueTo);
        //CC
        Skill(const Skill& s);
        //OpAssign
        Skill& operator=(const Skill& s);
        //Destruktor
        ~Skill();
        // getter
        string getID();
        string getName();
        string getElement();
        int getPower();
        int getMastery();
        string getDescription();
        // Lain-Lain
        void masteryUp();
        bool canBeLearned(string element);
};

#endif