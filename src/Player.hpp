#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Position.hpp"
#include "Inventory.hpp"
#include "Peta.hpp"
// #include "folderEngimon/Engimon.hpp"
#include "Breed.hpp"
//#include "Item.hpp"

//-------------------------------------
//BELUM SELESAI, MASIH BANYAK YG KURANG
//-------------------------------------

#define default_max_inven_cap 20      //Akan diubah sesuai kebutuhan
#define default_player_posX 0
#define default_player_posY 0

class Player
{
    private:
        string name;
        Position position;
        Position activeEngimonPosition;
        Peta *peta = new Peta();
        // Inventory<Engimon> inventoryEngimon;
        //Inventory<Item> inventoryItem;
        int activeEngimonIdx;
        int max_capacity;
    
    public:
        //ctor nanti hapus yang ga perlu aja
        Player();
        ~Player();

        //getter
        Engimon& get_active_engimon();
        Position get_active_engimon_pos();
        Peta getPeta();
        
        //setter
        void set_active_engimon(int engimonIdx);
        void set_active_engimon_pos(Position *pos);
        void change_active_engimon();

        Position activeEngimonPos();
        //void addItem(Item what);
        void use_item();
        void addEngimon(Engimon currEngimon);
        void addSkill(Skill itemSkill);
        void showInventory();
        void moveX(int direction);
        void moveY(int direction);
        void moveEngimon(int dirX, int dirY); //Kasih Exception 
        void get_battle();
        void get_breeding();
        void moveUP();
        void moveDOWN();
        void moveRIGHT();
        void moveLEFT();

        // IMPLEMENTASI
        void set_name(string);
};

Player::Player() : position(default_player_posX,default_player_posY), activeEngimonIdx(-1), max_capacity(default_max_inven_cap) 
//Untuk sekarang -1 artinya tidak ada Engimon
{
    // --------------initialize player di peta--------------------------//
    // 
    Cell *c = new Cell(0,0, CellType::grassland, Content::player);
    peta->setCell(c->getPosition().getX(), c->getPosition().getY(), *c);
    this->position.setX(0);
    this->position.setY(0);
    peta->showPeta();
    //-------------------------------------------------------------------//
} 

Player::~Player()
{
    delete this->peta;
}

Engimon& Player::get_active_engimon()
{
    if (this->activeEngimonIdx == -1)
    {
        throw "tidak ada Engimon Aktif";
    }
    
    return this->inventoryEngimon.getInventoryByIndex(this->activeEngimonIdx);
}

Peta Player::getPeta() {
    return *this->peta;
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

// void Player::addItem(Item what)
// {
//     if(this->max_capacity < this->inventoryEngimon.getTotalItem()){
//        this->inventoryItem.addInventory(what);   
//    } else {
//        throw "Inventory Penuh";
//    }
// }

void Player::use_item()
{
    //implementasi use item
}

void Player::addEngimon(Engimon currEngimon)
{
    if(this->max_capacity < this->inventoryEngimon.getTotalItem()){
        this->inventoryEngimon.addInventory(currEngimon);
    } else {
        throw "Inventory Penuh";
    }
}

void Player::showInventory()
{
    cout << "Engimon : " << endl;
    for(int i = 0; i < this->inventoryEngimon.getTotalItem(); i++){
        cout << this->inventoryEngimon.getInventoryByIndex(i).get_engimon_name() << endl;
    }
    /*
    cout << endl << "Skill Item : " << endl;
    for(int i = 0; i < this->inventoryItem.getTotalItem() ; i++){
        cout << this->inventoryItem.getInventoryByIndex(i) << " : ";
        cout << this->inventoryItem.getInventoryCountByIndex(i) << endl;
    }
    */
}

void Player::moveX(int dir)
{
    if (this->position.getY()+dir < 0 || this->position.getY()+dir >= this->peta->getSizeY())
    {
        cout << "Out of map. Please try different direction !" << endl;
    } else {
    
    // mengembalikan cell sebelumnya menjadi default
    Cell *c = new Cell(this->position.getX(), this->position.getY(), grassland, air);
    peta->setCell(c->getPosition().getX(), c->getPosition().getY(), *c);

    // mengubah cell tujuan
    this->position.setY(this->position.getY() + dir);
    Cell *d = new Cell(this->position.getX(), this->position.getY(), grassland, player);
    peta->setCell(d->getPosition().getX(), d->getPosition().getY(), *d);
    }
    //belum implementasiin batas di peta
}

void Player::moveY(int dir)
{
    //Untuk sementara begini

    if (this->position.getX()+dir < 0 || this->position.getX()+dir >= this->peta->getSizeX())
    {
        cout << "Out of map. Please try different direction !" << endl;
    } else {

    // mengembalikan cell sebelumnya menjadi default
    Cell *c = new Cell(this->position.getX(), this->position.getY(), grassland, air);
    peta->setCell(c->getPosition().getX(), c->getPosition().getY(), *c);

    // mengubah cell tujuan
    this->position.setX(this->position.getX() + dir);
    Cell *d = new Cell(this->position.getX(), this->position.getY(), grassland, player);
    peta->setCell(d->getPosition().getX(), d->getPosition().getY(), *d);
    }
    //belum implementasiin batas di peta
}

void Player::moveUP()
{
    moveY(-1);
}

void Player::moveDOWN()
{
    moveY(1);
}

void Player::moveRIGHT()
{
    moveX(1);
}

void Player::moveLEFT()
{
    moveX(-1);
}

void Player::moveEngimon(int dirX, int dirY) //Kasih Exception 
{
    //implementasi move engumon
    //Kemungkinan besar menyimpan posisi player sebelumnya
}

void Player::get_battle()
{
    //??????
}

void Player::get_breeding()
{
    int idxE1 = 0;
    int idxE2 = 1;
    Engimon e1 = inventoryEngimon.getInventoryByIndex(idxE1);
    Engimon e2 = inventoryEngimon.getInventoryByIndex(idxE2);

    string name;
    cout << "Give name for child : ";
    cin >> name;
    
    Breed breed(e1, e2, name);

    cout << "Breeding selesai!!" << endl;
    Engimon child = breed.get_child();

    inventoryEngimon.addInventory(child);

    //implementasi breeding (????????)
    //mungkin ini maksudnya proses breedingnya?
}

#endif