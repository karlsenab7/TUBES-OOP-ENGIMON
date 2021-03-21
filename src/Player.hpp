#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Position.hpp"
#include "Inventory.hpp"
//#include "Peta.hpp"
//#include "Engimon.hpp"
//#include "Item.hpp"

//-------------------------------------
//BELUM SELESAI, MASIH BANYAK YG KURANG
//-------------------------------------

#define default_max_inven_cap 20      //Akan diubah sesuai kebutuhan
#define default_player_posX 0
#define default_player_posY 0

class Player{
    private:
        Position position;
        Position activeEngimonPosition;
        Inventory<Engimon> inventoryEngimon;
        Inventory<Item> inventoryItem;
        int activeEngimonIdx;
        int max_capacity;
    
    public:
        //ctor nanti hapus yang ga perlu aja
        Player();
        ~Player();

        //getter
        Engimon& get_active_engimon();
        Position get_active_engimon_pos();
        
        //setter
        void set_active_engimon(int engimonIdx);
        void set_active_engimon_pos(Position *pos);
        
        Position activeEngimonPos();
        void addItem(Item what);
        void use_item();
        void addEngimon(Engimon currEngimon);
        void addSkill(Skill itemSkill);
        void showInventory();
        void moveX(int direction);
        void moveY(int direction);
        void moveEngimon(int dirX, int dirY); //Kasih Exception 
        void get_battle(Engimon enemy);
        void get_breeding(Engimon, Engimon);
}

Player::Player() : position(default_player_posX,default_player_posY), activeEngimonIdx(-1), max_capacity(default_max_inven_cap) {} //Untuk sekarang -1 artinya tidak ada Engimon

Player::~Player()
{
    //implementasi delete
}

Engimon& Player::get_active_engimon()
{
    if (this->activeEngimonIdx == -1)
    {
        throw "tidak ada Engimon Aktif";
    }
    
    return this->inventoryEngimon.getInventoryByIndex(this->activeEngimonIdx);
}

Position Player::activeEngimonPos()
{
    return this->activeEngimonPosition;
}
        
void Player::set_active_engimon(int engimonIdx)
{
    if (this->inventoryEngimon.get_total_stored_item() >= engimonIdx+1)
    {
        this->activeEngimonIdx = engimonIdx;
    }
}

void Player::set_active_engimon_pos(Position *pos)
{
    this->activeEngimonPosition.setX(pos->getX());
    this->activeEngimonPosition.setY(pos->getY());
}

void Player::addItem(Item what)
{
    //Cek apakah masih muat
    this->inventoryItem.addInventory(what);
}

void Player::use_item()
{
    //implementasi use item
}

void Player::addEngimon(Engimon currEngimon)
{
    this->inventoryEngimon.addInventory(currEngimon);
}

void Player::showInventory()
{
    //implementasi show inventory
}

void Player::moveX(int direction)
{
    //Untuk sementara begini
    this->position.setX(this->position.getX() + direction);
    //belum implementasiin batas di peta
}

void Player::moveY(int direction)
{
    //Untuk sementara begini
    this->position.setY(this->position.getY() + direction);
    //belum implementasiin batas di peta
}

void Player::moveEngimon(int dirX, int dirY) //Kasih Exception 
{
    //implementasi move engumon
    //Kemungkinan besar menyimpan posisi player sebelumnya
}

void Player::get_battle(Engimon enemy)
{
    //??????
}

void Player::get_breeding(Engimon, Engimon)
{
    //implementasi breeding (????????)
    //mungkin ini maksudnya proses breedingnya?
}

#endif