#ifndef SkillDatabase_HPP
#define SkillDatabase_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Element.hpp"

vector<string>  IDList;
vector<string> nameList;
vector<vector<Element>> elementList;
vector<int> powerList;
vector<string> descriptionList;
vector<bool> isUniqueList;
vector<string> uniqueToList;
int numOfData;

void checkSkillDatabase();

void initSkillDatabase()
{
    // IDList = new string[100];
    // nameList = new string[100];
    // elementList = new vector<Element>[100];
    // powerList = new int[100];
    // descriptionList = new string[100];
    // isUniqueList = new bool[100];
    // uniqueToList = new string[100];
    string namaFile = "Skill.txt";
    ifstream MyReadFile(namaFile.c_str());
    string line;
    int idx = 0;
    string elmt;
    int j = 0;
    string pow;
    stringstream ss;
    string b;

    string idTemp;
    string nameTemp;
    int powTemp;
    string descriptionTemp;
    bool isUniqeTemp;
    string uniqeToTemp;

    while (getline (MyReadFile, idTemp, ',') && idx < 100)
    {
        IDList.push_back(idTemp);

        getline(MyReadFile, nameTemp,',');
        nameList.push_back(nameTemp);
        
        getline(MyReadFile, elmt, ',');
        ss << elmt;
        vector<Element> elTemp;
        while(getline(ss, elmt, ' ')){
            Element baru(elmt);
            elTemp.push_back(baru);
            j++;
        }
        elementList.push_back(elTemp);
        ss.clear();
        j = 0;
        
        getline(MyReadFile,pow,',');
        ss << pow;
        ss >> powTemp;
        powerList.push_back(powTemp);
        ss.clear();
        
        getline(MyReadFile, descriptionTemp, ',');
        descriptionList.push_back(descriptionTemp);

        getline(MyReadFile, b,',');
        istringstream(b) >> boolalpha >> isUniqeTemp;
        isUniqueList.push_back(isUniqeTemp);

        getline(MyReadFile, uniqeToTemp, '\n');
        uniqueToList.push_back(uniqeToTemp);
        idx++;
    }
    numOfData = idx;
    MyReadFile.close();

    //checkSkillDatabase();
}


string getIDList(int idx){
    return IDList[idx];
}

string getNameList(int idx){
    return nameList[idx];
}
vector<Element> getElementList(int idx){
    return elementList[idx];
}
Element getElementListMember(int idx, int n){
    return elementList[idx][n];
}
int getPowerList(int idx){
    return powerList[idx];
}
string getDescriptionList(int idx){
    return descriptionList[idx];
}
bool getIsUniqueList(int idx){
    return isUniqueList[idx];
}
string getUniqueToList(int idx){
    return uniqueToList[idx];
}
int getSize(){
    return numOfData;
}

void checkSkillDatabase()
{
    cout << IDList.size() << endl;
    cout << nameList.size() << endl;
    cout << elementList.size() << endl;
    cout << powerList.size() << endl;
    cout << descriptionList.size() << endl;
    cout << isUniqueList.size() << endl;
    cout << uniqueToList.size() << endl;
}
#endif