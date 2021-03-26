
#ifndef __CELL_HPP__
#define __CELL_HPP__

#include <iostream>
#include "EngimonDatabase.hpp"
#include "Position.hpp"
using namespace std;

enum CellType {grassland, sea};
enum Content {player, engimon, air};

class Cell
{
private:
    Position position;
    CellType cellType;
    Content content;
    int idxEngimonInCell;

public:
    Cell(Position newPosition, CellType newCellType, Content newContent);
    Cell(int pX, int pY, CellType newCellType, Content newContent);
    Cell& operator=(const Cell& otherCell);

    // getter
    Position getPosition();
    CellType getCellType();
    char getCharCell();
    Content getContent();
    int getIdxEngimonInCell()
    {
        return idxEngimonInCell;
    }

    // setter
    void setPosition(Position newPosition);
    void setPosition(int pX, int pY);
    void setCellType(CellType newCellType);
    void setContent(Content newContent);
    void setIdxEngimonInCell(int idx);
};

Cell::Cell(Position newPosition, CellType newCellType, Content newContent)
{
    this->position = newPosition;
    this->cellType = newCellType;
    this->content = newContent;
    this->idxEngimonInCell = -1;
}

Cell::Cell(int pX, int pY, CellType newCellType, Content newContent)
{
    this->position.setX(pX);
    this->position.setY(pY);
    this->cellType = newCellType;
    this->content = newContent;
    this->idxEngimonInCell = -1;
}

Cell& Cell::operator=(const Cell& otherCell) {
    this->position = otherCell.position;
    this->cellType = otherCell.cellType;
    this->content = otherCell.content;
    this->idxEngimonInCell = otherCell.idxEngimonInCell;
    return *this;
}

Position Cell::getPosition()
{
    return this->position;
}

CellType Cell::getCellType()
{
    return this->cellType;
}

char Cell::getCharCell()
{
    EngimonDatabase db;

    if (content == Content::player)
    {
        return 'P';
    }
    else if (content == Content::engimon)
    {
        if (idxEngimonInCell == -1)
            return '-';

        //cout << "sdasd" << endl;
        Engimon e = db.get_engimon_by_idx(idxEngimonInCell);
        vector<Element> el = e.get_engimon_elements();
        //cout << "ssssss";
        if (el.size() > 1)
        {
            string el1 = el[0].get_element();
            string el2 = el[1].get_element();

            if ((el1 == "Fire" && el2 == "Electric") || (el1 == "Electric" && el2 == "Fire") )
            {
                if (e.get_level() >= 30)
                    return 'L';
                else
                    return 'l';
            }
            else if ((el1 == "Water" && el2 == "Ice") || (el1 == "Ice" && el2 == "Water") )
            {
                if (e.get_level() >= 30)
                    return 'S';
                else
                    return 's';
            }
            else
            {
                if (e.get_level() >= 30)
                    return 'N';
                else
                    return 'n';
            }
        }
        else
        {
            if (el[0].get_element() == "Fire")
            {
                if (e.get_level() >= 30)
                    return 'F';
                else
                    return 'f';
            }
            else if (el[0].get_element() == "Water")
            {
                if (e.get_level() >= 30)
                    return 'W';
                else
                    return 'w';
            }
            else if (el[0].get_element() == "Ice")
            {
                if (e.get_level() >= 30)
                    return 'I';
                else
                    return 'i';
            }
            else if (el[0].get_element() == "Ground")
            {
                if (e.get_level() >= 30)
                    return 'G';
                else
                    return 'g';
            }
            else
            {
                if (e.get_level() >= 30)
                    return 'E';
                else
                    return 'e';
            }
        }

    }
    else if (content == Content::air)
    {
        if (cellType == CellType::grassland)
        {
            return '-';
        } else if (cellType == CellType::sea)
        {
            return 'o';
        }
    }
    
    return '#';
}

Content Cell::getContent()
{
    return this->content;
}

void Cell::setPosition(Position newposition)
{
    this->position.setX(newposition.getX());
    this->position.setY(newposition.getY());
}

void Cell::setPosition(int pX, int pY)
{
    this->position.setX(pX);
    this->position.setY(pY);
}

void Cell::setCellType(CellType newCellType)
{
    this->cellType = newCellType;
}

void Cell::setContent(Content newContent)
{
    this->content = newContent;
}

void Cell::setIdxEngimonInCell(int idx) {
    this->idxEngimonInCell = idx;
}

#endif
