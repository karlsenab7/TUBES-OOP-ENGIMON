
#ifndef __CELL_HPP__
#define __CELL_HPP__

#include "Point.hpp"

enum CellType
{
    grassland,
    sea
};
enum Content
{
    player,
    engimon,
    air
};

class Cell
{
private:
    Point position;
    CellType cellType;
    Content content;
    int idxEngimonInCell;

public:
    Cell(Point newPosition, CellType newCellType, Content newContent);
    Cell(int pX, int pY, CellType newCellType, Content newContent);

    // getter
    Point getPosition();
    CellType getCellType();
    char getCharCell();
    Content getContent();

    // setter
    void setPosition(Point newPosition);
    void setPosition(int pX, int pY);
    void setCellType(CellType newCellType);
    void setContent(Content newContent);
    void setIdxEngimonInCell(int idx);
};

Cell::Cell(Point newPosition, CellType newCellType, Content newContent)
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

Point Cell::getPosition()
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

void Cell::setPosition(Point newposition)
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
