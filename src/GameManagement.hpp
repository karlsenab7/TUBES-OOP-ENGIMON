#ifndef __GAME_MANAGEMENT_HPP__
#define __GAME_MANAGEMENT_HPP__

#include<iostream>
#include "Peta.hpp"
#include "Player.hpp"
#include "Engimon.hpp"
#include "Input.hpp"
#include "SkillDatabase.hpp"

using namespace std;

class GameManagement
{
private:
    Player *p = new Player();
public:
    GameManagement();
    ~GameManagement();

    void run();
    void newGame();
    void conti();
    void exit();
    void loadData();
    void save();
    void executeCommand(string);

};

GameManagement::GameManagement()
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
    
    p->set_name(name);
    loadData();
}

void GameManagement::loadData()
{
    initSkillDatabase();
}

void GameManagement::run()
{
    Input in;

    while (1)
    {
        p->showPeta();
        cout << "\n======================================\n";
        executeCommand(in.getInput());
        cout << "======================================\n\n";
    }
    
}

void GameManagement::executeCommand(string cmd)
{
    if (cmd == "w")
    {
        p->moveUP();
    }
    else if (cmd == "a")
    {
        p->moveLEFT();
    }
    else if (cmd == "s")
    {
        p->moveDOWN();
    }
    else if (cmd == "d")
    {
        p->moveRIGHT();
    }
    else if (cmd == "battle")
    {
        p->get_battle();
    }
    else if (cmd == "i")
    {
        p->inventoryMode();
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