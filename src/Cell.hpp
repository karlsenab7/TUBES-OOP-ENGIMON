
#ifndef __CELL_HPP__
#define __CELL_HPP__

#include "Position.hpp"

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
    Cell Cell::operator=(const Cell& otherCell);

    // getter
    Position getPosition();
    CellType getCellType();
    char getCharCell();
    Content getContent();

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
}

Cell::Cell(int pX, int pY, CellType newCellType, Content newContent)
{
    this->position.setX(pX);
    this->position.setY(pY);
    this->cellType = newCellType;
    this->content = newContent;
}

Cell Cell::operator=(const Cell& otherCell) {
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
    if (content == Content::player)
    {
        return 'P';
    }
    else if (content == Content::engimon)
    {
        /* code */
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
