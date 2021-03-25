#ifndef SkillDatabase_HPP
#define SkillDatabase_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Element.hpp"
class SkillDatabase {
    private:
        string*  IDList;
        string* nameList;
        vector<Element>* elementList;
        int* powerList;
        string* descriptionList;
        bool* isUniqueList;
        string* uniqueToList;
        int size;
    public:
        SkillDatabase(){
            IDList = new string[100];
            nameList = new string[100];
            elementList = new vector<Element>[100];
            powerList = new int[100];
            descriptionList = new string[100];
            isUniqueList = new bool[100];
            uniqueToList = new string[100];
            string namaFile = "Skill.txt";
            ifstream MyReadFile(namaFile.c_str());
            string line;
            int idx = 0;
            string elmt;
            int j = 0;
            string pow;
            stringstream ss;
            string b;
            while (getline (MyReadFile, IDList[idx], ',') && idx < 100){
                getline(MyReadFile, nameList[idx],',');
                getline(MyReadFile, elmt, ',');
                ss << elmt;
                while(getline(ss, elmt, ' ')){
                    Element baru(elmt);
                    elementList[idx].push_back(baru);
                    j++;
                }
                ss.clear();
                j = 0;
                getline(MyReadFile,pow,',');
                ss << pow;
                ss >> powerList[idx];
                ss.clear();
                getline(MyReadFile, descriptionList[idx], ',');
                getline(MyReadFile, b,',');
                istringstream(b) >> boolalpha >> isUniqueList[idx];
                getline(MyReadFile, uniqueToList[idx], '\n');
                idx++;
            }
            size = idx;
            MyReadFile.close();
        }
        ~SkillDatabase(){
            delete[] IDList;
            delete[] nameList;
            delete[] elementList;
            delete[] powerList;
            delete[] descriptionList;
            delete[] isUniqueList;
            delete[] uniqueToList;
        }
        string getIDList(int idx){
            return this->IDList[idx];
        }
        
        string getNameList(int idx){
            return this->nameList[idx];
        }
        vector<Element> getElementList(int idx){
            return this->elementList[idx];
        }
        Element getElementListMember(int idx, int n){
            return this->elementList[idx][n];
        }
        int getPowerList(int idx){
            return this->powerList[idx];
        }
        string getDescriptionList(int idx){
            return this->descriptionList[idx];
        }
        bool getIsUniqueList(int idx){
            return this->isUniqueList[idx];
        }
        string getUniqueToList(int idx){
            return this->uniqueToList[idx];
        }
        int getSize(){
            return this->size;
        }
};
#endif