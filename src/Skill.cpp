#include "Skill.hpp"

Skill::Skill(string ID, string name, string element, int* learnableBy, int power, string desc, bool isUnique, string uniqueTo){
    this->ID  = ID;
    this->name = name;
    this->element = element;
    this->learnableBy = new int[5];
    for(int i = 0; i < 5; i++){
        this->learnableBy[i] = learnableBy[i];
    }
    this->description = desc;
    this->isUnique = isUnique;
    this->uniqueTo = uniqueTo;
    this->mastery = 1;
}
Skill::Skill(const Skill& s){
    this->ID  = s.ID;
    this->name = s.name;
    this->element = s.element;
    this->learnableBy = new int[5];
    for(int i = 0; i < 5; i++){
        this->learnableBy[i] = s.learnableBy[i];
    }
    this->description = s.description;
    this->isUnique = s.isUnique;
    this->uniqueTo = s.uniqueTo;
    this->mastery = s.mastery;
}
Skill& Skill::operator=(const Skill& s){
    this->ID  = s.ID;
    this->name = s.name;
    this->element = s.element;
    for(int i = 0; i < 5; i++){
        this->learnableBy[i] = s.learnableBy[i];
    }
    this->description = s.description;
    this->isUnique = s.isUnique;
    this->uniqueTo = s.uniqueTo;
    this->mastery = s.mastery;
}
Skill::~Skill(){
    delete[] this->learnableBy;
}
string Skill::getID(){return this->ID;}
string Skill::getName(){return this->name;}
string Skill::getElement(){return this->element;}
int Skill::getPower(){return this->power;}
int Skill::getMastery(){return this->mastery;}
string Skill::getDescription(){return this->description;}
void Skill::masteryUp(){this->mastery++;}
bool Skill::canBeLearned(string element){
    //[Fire, Water, Electric, Ground, Ice]
    if(strcmp(element.c_str(), "Fire") && this->learnableBy[0]){
        return true;
    }else if(strcmp(element.c_str(), "Water") && this->learnableBy[1]){
        return true;
    }else if(strcmp(element.c_str(), "Electric") && this->learnableBy[2]){
        return true;
    }else if(strcmp(element.c_str(), "Ground") && this->learnableBy[3]){
        return true;
    }else if(strcmp(element.c_str(), "Ice") && this->learnableBy[4]){
        return true;
    }
    return false;
}