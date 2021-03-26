#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include <iostream>
#include <vector>
#include "Engimon.hpp"
// #include "Position.hpp"
using namespace std;


//----------------------------------------------------------------------------
// MASIH KURANG
// REMOVE & ADD MASIH HARUS DIPERBAIKI & DIBEDAKAN PER CLASS
//----------------------------------------------------------------------------

template <class T>
class Inventory
{
    private:
        int max_capacity;
        int total_stored_item;
        vector<T> arrOfElements;
        vector<int> countElement;

    public:
        Inventory();
        ~Inventory();

        // getter
        int get_max_capacity();
        int get_total_stored_item();
        vector<T>& getInventory();
        vector<int>& getInventoryCount();
        int getInventoryCountByIndex(int index);
        T& getInventoryByIndex(int index);
        //int getJumlahItem(int index);
        int getJumlahItem(int index){
            return this->countElement[index];
        }
        int getTotalItem(){
            int sum = 0;
            for(int i = 0; i < this->countElement.size(); i++){
                sum += this->countElement[i];
            }
            return sum;
        }

        // setter
        void set_max_capacity(int newMax);
        void set_total_stored_item(int newTotal);
        void addInventory(T items);
        void removeInventory(int index);
        bool isEqual(T, T);
};

template <class T>
Inventory<T>::Inventory() : total_stored_item(0), max_capacity(50)
{
    this->arrOfElements.clear();
    this->countElement.clear();
    //cout << "Success Initialize : size =  " << this->arrOfElements.size() << " & max = " << this->arrOfElements.max_size() << endl;
}

template <class T>
Inventory<T>::~Inventory()
{
    delete &this->arrOfElements;
    delete &this->countElement;
}


template <class T>
int Inventory<T>::get_max_capacity()
{
    return max_capacity;
}


template <class T>
int Inventory<T>::get_total_stored_item()
{
    return this->total_stored_item;
}

template <class T>
vector<T>& Inventory<T>::getInventory()
{
    return this->arrOfElements;
}

template <class T>
vector<int>& Inventory<T>::getInventoryCount()
{
    return this->countElement;
}

template <class T>
int Inventory<T>::getInventoryCountByIndex(int index)
{
    return this->countElement.at(index);
}

template <class T>
T& Inventory<T>::getInventoryByIndex(int index)
{
    /*
    Contoh implementasi
    -------------------------------------
    test *obj2;
    obj2 = &P.getInventoryByIndex(0);
    obj2->setint(2000);
    test t2 = P.getInventoryByIndex(0);

    t2.printWhat();     //output : 2000
    obj2->printWhat();  //output : 2000
    -------------------------------------
    */
    return this->arrOfElements.at(index);
}

/*
template <class T>
void Inventory<T>::set_max_capacity(int newMax)
{
    if(this->max_capacity <= newMax){
        this->max_capacity = newMax;    
    } else {
        throw "New Max Capacity is lower than Current Max Capacity";
    }
}
*/

template <class T>
void Inventory<T>::set_total_stored_item(int newTotal)
{
    this->total_stored_item = newTotal;
}

template <class T>
void Inventory<T>::addInventory(T items)
{
    try
    {
        
        /* code */
        if (this->total_stored_item >= this->max_capacity)
        {
            
            throw "INVENTORY IS FULL";
        }

        if(this->total_stored_item > 0){   //arrOfElements empty
            
            for (int i = 0 ; i < this->arrOfElements.size(); i++)
            {
                
                if(isEqual(this->arrOfElements[i], items)){
                    
                    this->countElement[i]++;
                    //cout << "Berhasil ditambah" << endl;
                    total_stored_item++;
                    return;
                }
            }
            cout << endl;
        }

        this->total_stored_item = this->total_stored_item + 1;
        this->arrOfElements.push_back(items);
        this->countElement.push_back(1);
        //cout << "Capacity = " << this->arrOfElements.capacity() << endl;
        //cout << this->arrOfElements.size() << endl;
        //cout << "Barang ditambahkan" << endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template <>
bool Inventory<Engimon>::isEqual(Engimon e1, Engimon e2)
{
    return 
    e1.get_species_name() == e2.get_species_name() && 
    e1.get_engimon_name() == e2.get_engimon_name() &&
    e1.get_level() == e1.get_level();
}

template <>
bool Inventory<Skill>::isEqual(Skill s1, Skill s2)
{

    return s1.getID() == s2.getID();
}

// template <class T>
// void Inventory<T>::addInventory(const T& items)
// {
//     this->total_stored_item = this->total_stored_item + 1;
//     this->arrOfElements.push_back(items);
//     this->countElement.push_back(1);
// }

template <class T>
void Inventory<T>::removeInventory(int index)
{
    if(this->max_capacity > index){
        int j = 0;
        vector<int>::iterator k = this->countElement.begin();
        for (auto i = this->arrOfElements.begin(); i != this->arrOfElements.end(); i++, j++, k++)
        {
            if(j == index){
                if(this->countElement[j] > 1){
                    this->countElement[j]--;
                } else {
                    this->arrOfElements.erase(i);
                    this->countElement.erase(k);
                }
                this->total_stored_item = this->total_stored_item - 1;
            }
        }
    }
}


// void Inventory<T>::removeInventory(int index)
// {
//     if(this->arrOfElements.empty() == false){
//         int j = 0;
//         vector<int>::iterator k = this->countElement.begin();
//         for (auto i = this->arrOfElements.begin(); i != this->arrOfElements.end(); i++, j++, k++)
//         {
//             if(j == index){
//                     this->arrOfElements.erase(i);
//                     this->countElement.erase(i);
//                 }
//             this->total_stored_item = this->total_stored_item - 1;
//         }
//     }
// }

#endif