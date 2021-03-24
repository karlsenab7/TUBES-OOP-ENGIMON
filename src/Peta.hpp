
#ifndef __PETA_HPP__
#define __PETA_HPP__

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "Cell.hpp"
using namespace std;

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
    vector<vector<Cell>> arrOfCell;
    vector<int> arrOfEngimon; // tunggu Engimon.hpp selesai

public:
    Peta(int x, int y);

    void generatePeta();
    void showLegend();
    void spawnMonster(vector<int> arrOfEngimonGlobal);
    void showPetaNLegend();
};

Peta::Peta(int x, int y)
{
    this->sizeX = x;
    this->sizeY = y;

    for (int i = 0; i < x; i++)
    {
        vector<Cell> temp;
        for (int j = 0; j < y; j++)
        {
            Cell c(i, j, CellType::grassland, Content::air);
            temp.push_back(c);
        }
        this->arrOfCell.push_back(temp);
    }
}

void Peta::generatePeta()
{
    // for (int i = 0; i < this->sizeX; i++)
    // {
    //     for (int j = 0; j < this->sizeY; j++)
    //     {
    //         char ui = arrOfCell[i][j].getCharCell();
    //         cout << ui;
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    string filename;
    string dir = "map/";
	string myText;
    cin >> filename;
	cout << endl;
	ifstream MyReadFile(dir + filename); // buka file

	if (MyReadFile.is_open()) // jika file berhasil terbuka
	{
		while (getline(MyReadFile, myText))
		{
			// memproses masukkan dari file agar dapat dibaca oleh program
			cout << myText << endl;
		}
	}
	else
	{
		cout << "format file salah atau file tidak ditemukan" << endl;
	}
	cout << endl;
	
	// menutup file
	MyReadFile.close();
}

void Peta::showLegend()
{
    cout << "Keterangan" << endl
         << endl;
    cout << "W/w: Water engimon                P: Player" << endl;
    cout << "I/i: Ice engimon                  X: Active Engimon" << endl;
    cout << "F/f: Fire engimon" << endl;
    cout << "G/g: Ground engimon               - : Grassland" << endl;
    cout << "E/e: Electric engimon             o : Sea" << endl;
    cout << "L/l: Fire/Electric engimon" << endl;
    cout << "S/s: Water/Ice engimon" << endl;
    cout << "N.n: Water/Ground engimon" << endl;
}

void Peta::showPetaNLegend()
{
    this->generatePeta();
    this->showLegend();
}

void Peta::spawnMonster(vector<int> arrOfEngimonGlobal) // ganti int dengan Engimon
{
    int x = 0;
    int y = 0;
    do
    {
        srand(time(nullptr)); // use current time as seed for random generator
        x = rand() % this->sizeX;
        y = rand() % this->sizeY;
    } while ((arrOfCell[x][y].getContent() != Content::air));

    this->arrOfCell[x][y].setContent(Content::engimon);
    int idx = arrOfEngimon.size();
    int i = rand() % arrOfEngimonGlobal.size();
    arrOfEngimon.push_back(arrOfEngimonGlobal[i]);
    arrOfCell[x][y].setIdxEngimonInCell(idx);
    // random engimon yang dimasukkan ke cell
}

#endif