
#ifndef __PETA_HPP__
#define __PETA_HPP__

#include "Vector.hpp"
#include "Cell.hpp"


//   ____       _                    _____      _                 _ 
//  |  _ \     | |                  / ____|    | |               (_)
//  | |_) | ___| |_   _ _ __ ___   | (___   ___| | ___  ___  __ _ _ 
//  |  _ < / _ \ | | | | '_ ` _ \   \___ \ / _ \ |/ _ \/ __|/ _` | |
//  | |_) |  __/ | |_| | | | | | |  ____) |  __/ |  __/\__ \ (_| | |
//  |____/ \___|_|\__,_|_| |_| |_| |_____/ \___|_|\___||___/\__,_|_|
                                                                 
class Peta
{
private:
    int sizeX;
    int sizeY;
    Vector<Cell, 100> *arrOfCell;
    // Vector<Engimon, 100> arrOfEngimon; // tunggu Engimon.hpp selesai
public:
    Peta();
    ~Peta();
};

Peta::Peta(/* args */)
{
}

Peta::~Peta()
{
}


// vector<Cell> arrOfCell; // belum tau
//     vector<Engimon> arrOfEngimon; // belum tau
//     int sizeX;
//     int sizeY;

//     methods:
//     // getter

//     // setter


//     void generatePeta(); // 
//     void legenda();
//     void spawnMonster();


#endif