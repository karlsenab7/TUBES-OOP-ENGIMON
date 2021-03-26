#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <iostream>
#include<vector>
#include "Position.hpp"
#include "Inventory.hpp"
#include "Peta.hpp"
#include "Engimon.hpp"
#include "Skill.hpp"
#include "Battle.hpp"
// #include "folderEngimon/Engimon.hpp"
#include "Breed.hpp"
//#include "Item.hpp"

using namespace std;

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
        Inventory<Engimon> inventoryEngimon;
        Inventory<Skill> inventorySkill;
        int activeEngimonIdx;
        //int max_capacity;
    
    public:
        //ctor nanti hapus yang ga perlu aja
        Player();
        ~Player();

        //getter
        Engimon& get_active_engimon();
        Position get_active_engimon_pos();
        Peta getPeta();
        
        // //setter
        void set_active_engimon(int engimonIdx);
        void set_active_engimon_pos(Position *pos);
        void change_active_engimon();

        Position activeEngimonPos();
        //void addItem(Item what);
        void use_item();
        void addEngimon(Engimon);
        void addSkill(Skill);
        // void showInventory();
        void moveX(int direction);
        void moveY(int direction);
        // void moveEngimon(int dirX, int dirY); //Kasih Exception 
        void get_battle();
        void get_breeding();
        void moveUP();
        void moveDOWN();
        void moveRIGHT();
        void moveLEFT();

        // IMPLEMENTASI
        void set_name(string);
        void showPeta();
        void showEngimonInventory();
        void showSkillInventory();
        void inventoryMode();
        void invCommand();
};

Player::Player() : position(default_player_posX,default_player_posY), activeEngimonIdx(-1)
//Untuk sekarang -1 artinya tidak ada Engimon
{
    // --------------initialize player di peta--------------------------//
    // 
    Cell *c = new Cell(0,0, CellType::grassland, Content::player);
    peta->setCell(c->getPosition().getX(), c->getPosition().getY(), *c);
    this->position.setX(0);
    this->position.setY(0);

    Engimon e;
    e.set_engimon_name("Starter Pack Engimon");
    addEngimon(e);
    // peta->showPeta();
    //-------------------------------------------------------------------//
} 

Player::~Player()
{
    delete this->peta;
}

void Player::set_name(string name)
{
    this->name = name;
}

void Player::showPeta()
{
    peta->showPetaNLegend();
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

// void Player::set_active_engimon_pos(Position *pos)
// {
//     this->activeEngimonPosition.setX(pos->getX());
//     this->activeEngimonPosition.setY(pos->getY());
// }

void Player::addSkill(Skill what)
{
    try
    {
        cout << "d\n";
        this->inventorySkill.addInventory(what);
    }
    catch(string& e)
    {
        cout << e << '\n';
    }
    
}

void Player::use_item()
{
    //implementasi use item
    cout << "Select Skill item : ";
    int skill;
    cin >> skill;
    if (skill > inventorySkill.getInventory().size() || skill < 1)
    {
        cout << "Input is incorrect!!\n\n";
    }
    else
    {
        cout << "Select target engimon!!";
        int engimon;
        cin >> engimon;
        if (engimon > inventoryEngimon.getInventory().size() || engimon < 1)
        {
            cout << "Input is incorrect!!\n\n";
        }
        else
        {
            if (inventoryEngimon.getInventoryByIndex(engimon-1).is_skill_already_learned(inventorySkill.getInventoryByIndex(skill-1)))
            {
                cout << "Skill is already learned\n\n";
            }
            else
            {
                inventoryEngimon.getInventoryByIndex(engimon-1).add_skill(inventorySkill.getInventoryByIndex(skill-1));
            }
        }
    }
}

void Player::addEngimon(Engimon what)
{
    try
    {
        this->inventoryEngimon.addInventory(what);
    }
    catch(string& e)
    {
        cout << e << '\n';
    }
}

// void Player::showInventory()
// {
//     cout << "Engimon : " << endl;
//     for(int i = 0; i < this->inventoryEngimon.getTotalItem(); i++){
//         cout << this->inventoryEngimon.getInventoryByIndex(i).get_engimon_name() << endl;
//     }
//     /*
//     cout << endl << "Skill Item : " << endl;
//     for(int i = 0; i < this->inventoryItem.getTotalItem() ; i++){
//         cout << this->inventoryItem.getInventoryByIndex(i) << " : ";
//         cout << this->inventoryItem.getInventoryCountByIndex(i) << endl;
//     }
//     */
// }

void Player::moveX(int dir)
{
    if (this->position.getY()+dir < 0 || this->position.getY()+dir >= this->peta->getSizeY())
    {
        cout << "Out of map. Please try different direction !" << endl;
    } else {

        
        
        // mengembalikan cell sebelumnya menjadi default
        //Cell *c = new Cell(this->position.getX(), this->position.getY(), grassland, air);
        //peta->setCell(c->getPosition().getX(), c->getPosition().getY(), *c);

        peta->setCellContent(this->position, Content::air);

        // mengubah cell tujuan
        this->position.setY(this->position.getY() + dir);

        Position p(position.getX(), position.getY());

        if (peta->getCell(p.getX(), p.getY()).getContent() == Content::engimon)
        {
            get_battle();
            return;
        }
        //Cell *d = new Cell(this->position.getX(), this->position.getY(), grassland, player);
        //peta->setCell(d->getPosition().getX(), d->getPosition().getY(), *d);
        
        peta->setCellContent(this->position, Content::player);    
    }
    //belum implementasiin batas di peta
}

void Player::moveY(int dir)
{
    if (this->position.getX()+dir < 0 || this->position.getX()+dir >= this->peta->getSizeX())
    {
        cout << "Out of map. Please try different direction !" << endl;
    } else {
        
        // mengembalikan cell sebelumnya menjadi default
        //Cell *c = new Cell(this->position.getX(), this->position.getY(), grassland, air);
        //peta->setCell(c->getPosition().getX(), c->getPosition().getY(), *c);
        
        peta->setCellContent(this->position, Content::air);
        
        this->position.setX(this->position.getX() + dir);

        Position p(position.getX(), position.getY());

        if (peta->getCell(p.getX(), p.getY()).getContent() == Content::engimon)
        {
            get_battle();
            return;
        }

        // mengubah cell tujuan
        //this->position.setX(this->position.getX() + dir);
        //Cell *d = new Cell(this->position.getX(), this->position.getY(), grassland, player);
        //peta->setCell(d->getPosition().getX(), d->getPosition().getY(), *d);
        
        peta->setCellContent(this->position, Content::player);    
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

// void Player::moveEngimon(int dirX, int dirY) //Kasih Exception 
// {
//     //implementasi move engumon
//     //Kemungkinan besar menyimpan posisi player sebelumnya
// }

void Player::get_battle()
{
    if (activeEngimonIdx >= 0)
    {
        EngimonDatabase db;
        int idxEnemy = peta->getCell(position.getX(), position.getY()).getIdxEngimonInCell();
        cout << idxEnemy << "--------";
        if (idxEnemy < 0)
            return;

        Battle battle(activeEngimonIdx, db.get_engimon_by_idx(idxEnemy), inventoryEngimon, inventorySkill);
        battle.fight();
    }
}

void Player::get_breeding()
{

    int idxE1 = 0;
    int idxE2 = 1;

    cout << "Select Engimon 1 : ";
    cin >> idxE1;
    cout << "Select Engimon 2 : ";
    cin >> idxE2;
    
    if (
        idxE2 == idxE1 || 
        idxE1 > inventoryEngimon.getInventory().size() || 
        idxE2 > inventoryEngimon.getInventory().size() ||
        idxE1 < 1 ||
        idxE2 < 1
        )
    {
        cout << "Input is incorrect!!\n\n";
        return;
    }

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


void Player::inventoryMode()
{
    cout << "Open inventory\n\n";
    string cmd;
    string mode = "1";
    do
    {
        if (mode == "1")
        {
            showEngimonInventory();
        }
        else if (mode == "2")
        {
            showSkillInventory();
        }
        else if (mode == "3")
        {
            int en;
            try
            {
            
                cout << "select engimon : ";
                cin >> en;
                en += 0;
                if (en > inventoryEngimon.getInventory().size())
                {
                    cout << "Input is incorrect!!\n\n";
                
                }
                else
                {
                    activeEngimonIdx = en - 1;
                }

                showEngimonInventory();
            }
            catch(const exception& e)
            {
                cout << "Input is incorrect!!\n";
            }
            
        }
        else if (mode == "4")
        {
            use_item();
        }
        else if (mode == "5")
        {
            get_breeding();
        }
        


        invCommand();
        cout << "\n<<< " ;
        cin >> cmd;
        mode = cmd;

    } while (mode != "0");
    cout << "Close Inventory\n";
}

void Player::invCommand()
{
    cout << endl;
    cout << "1. Show Engimon Inventory\n";
    cout << "2. Show Skill Inventory\n";
    cout << "3. Switch Active Engimon\n";
    cout << "4. Learn Skill To Engimon\n";
    cout << "5. Breeding Engimon\n";
    cout << "0. Exit\n";
    cout << "Input a Number!\n";
}


void Player::showEngimonInventory()
{
    cout << "Engimon Inventory\n";
    cout << "-----------------------------------\n";
    if (inventoryEngimon.getTotalItem() == 0)
    {
        cout << "** ENGIMON INVENTORY IS EMPTY **" << endl;
    }
    else
    {
        vector<int> countEl = inventoryEngimon.getInventoryCount();
        vector<Engimon> el = inventoryEngimon.getInventory();
        for (int i = 0; i < countEl.size(); i++)
        {
            string batas;
            
            if (activeEngimonIdx == i)
                batas = ".* ";
            else
                batas = ".  ";
            
            cout << i + 1 << batas;
            cout << countEl[i] << "x ";
            cout << el[i].get_engimon_name() << " - Level " << el[i].get_level() << endl;
        }
        
    }
    cout << "-----------------------------------\n";
    
}

void Player::showSkillInventory()
{
    cout << "Skill Item Inventory\n";
    cout << "-----------------------------------\n";
    if (inventorySkill.getTotalItem() == 0)
    {
        cout << "** SKILL INVENTORY IS EMPTY **" << endl;
    }
    else
    {
        vector<int> countEl = inventorySkill.getInventoryCount();
        vector<Skill> s = inventorySkill.getInventory();
        for (int i = 0; i < countEl.size(); i++)
        {
            cout << i + 1 << ".  ";
            cout << countEl[i] << "x ";
            cout << s[i].getName() 
            << " - Power :  " 
            << s[i].getPower() 
            << " - Mastery Level : "
            << s[i].getMastery()
            << endl;
        }
        
    }
    cout << "-----------------------------------\n";
    
}

#endif