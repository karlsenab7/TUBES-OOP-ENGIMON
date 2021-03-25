#include "Skill.hpp"

Skill::Skill(string ID, string name, vector<Element> element, int power, string desc, bool isUnique, string uniqueTo){
    this->ID  = ID;
    this->name = name;
    for(int i = 0; i < element.size(); i++){
        this->element.push_back(element[i]);
    }
    this->description = desc;
    this->isUnique = isUnique;
    this->uniqueTo = uniqueTo;
    this->mastery = 1;
}
Skill::Skill(const Skill& s){
    this->ID  = s.ID;
    this->name = s.name;
    for(int i = 0; i < element.size(); i++){
        this->element.push_back(element[i]);
    }
    this->description = s.description;
    this->isUnique = s.isUnique;
    this->uniqueTo = s.uniqueTo;
    this->mastery = s.mastery;
}
Skill& Skill::operator=(const Skill& s){
    this->ID  = s.ID;
    this->name = s.name;
    for(int i = 0; i < element.size(); i++){
        this->element.push_back(element[i]);
    }
    this->description = s.description;
    this->isUnique = s.isUnique;
    this->uniqueTo = s.uniqueTo;
    this->mastery = s.mastery;
}
string Skill::getID(){return this->ID;}
string Skill::getName(){return this->name;}
vector<Element> Skill::getElement(){return this->element;}
int Skill::getPower(){return this->power;}
int Skill::getMastery(){return this->mastery;}
string Skill::getDescription(){return this->description;}
void Skill::masteryUp(){this->mastery++;}
bool Skill::canBeLearned(Element element){
    vector<Element>::iterator lokasi;
    lokasi = find(this->element.begin(), this->element.end(), element);
    if( lokasi - this->element.begin() < this->element.size() ){
        return true;
    }
    return false;
}
void Skill::print(){
    cout << "ID: " << this->ID << endl;
    cout << "Nama: " << this->name << endl;
    cout << "Elements: ";
    for(int i = 0; i < this->element.size(); i++){
        cout << this->element[i].get_element();
        if(i != this->element.size()-1){
            cout << ",";
        }
    }
    cout << endl;
    cout << "Power: " << this->power << endl;
    cout << "Deskripsi: " << this->description << endl;
    if(isUnique){
        cout << "Unique to: " << this->uniqueTo << endl;
    }
}