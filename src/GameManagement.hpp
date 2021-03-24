#ifndef __GAME_MANAGEMENT_HPP__
#define __GAME_MANAGEMENT_HPP__

#include<iostream>
#include "Peta.hpp"
#include "Player.hpp"
#include "Input.hpp"

using namespace std;

class GameManagement
{
private:
    Peta map;
    Player p;
public:
    GameManagement();
    ~GameManagement();

    void run();
    void newGame();
    void conti();
    void exit();
    void loadData();
    void exit();
    void save();
    void executeCommand(string);

};

GameManagement::GameManagement() : map(10, 10)
{
}

GameManagement::~GameManagement()
{
}

void GameManagement::newGame()
{
    string name = "";
    while (name.length() != 0)
    {
        cout << "Masukkan nama anda : ";
        cin >> name;
    }
    
    p.set_name(name);
    loadData();
}

void GameManagement::run()
{
    Input in;

    while (1)
    {
        executeCommand(in.getInput());
    }
    
}

void GameManagement::executeCommand(string cmd)
{
    if (cmd == "w")
    {
        p.moveUP();
    }
    else if (cmd == "a")
    {
        p.moveLEFT();
    }
    else if (cmd == "s")
    {
        p.moveDOWN();
    }
    else if (cmd == "d")
    {
        p.moveRIGHT();
    }
    else if (cmd == "breed")
    {
        p.get_breeding();
    }
    else if (cmd == "battle")
    {
        p.get_battle();
    }
    else if (cmd == "i")
    {
        p.showInventory();
    }
    else if (cmd == "use")
    {
        p.use_item();
    }
    else if (cmd == "e")
    {
        p.change_active_engimon();
    }
}

#endif


/*
GameManagement (main)
    Peta main; // update setiap saat
    Player player1;
    run(); // 
    newGame();
    continue();
    exit();
    loadData();
    save(); // kalo gabut

*/