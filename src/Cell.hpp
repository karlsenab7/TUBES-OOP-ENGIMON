
#ifndef __CELL_HPP__
#define __CELL_HPP__

#include "Position.hpp"


enum CellType {grassland, sea};
enum Content {player, engimon, air};

class Cell
{
private:
    Position* position;
    CellType cellType;
    Content content;
public:
    Cell(Position newPosition, CellType newCellType, Content newContent);  
    Cell(int pX, int pY, CellType newCellType, Content newContent);
    ~Cell();

    // getter
    Position getPosition();
    CellType getCellType();
    Content getContent();

    // setter
    void setPosition(Position newPosition);
    void setPosition(int pX, int pY);
    void setCellType(CellType newCellType);
    void setContent(Content newContent);
};

Cell::Cell(Position newPosition, CellType newCellType, Content newContent)
{
    this->position = &newPosition;
    this->cellType = newCellType;
    this->content = newContent;
}

Cell::Cell(int pX, int pY, CellType newCellType, Content newContent)
{
    this->position->setX(pX);
    this->position->setY(pY);
    this->cellType = newCellType;
    this->content = newContent;
}

Cell::~Cell()
{
    delete this->position;
}

Position Cell::getPosition() {
    // Position cpyPosition = new Position(this->position->getX(), this->position->getY());
    return *position;
}

CellType Cell::getCellType() {
    return this->cellType;
}
Content Cell::getContent() {
    return this->content;
}

void Cell::setPosition(Position newPosition) {
    this->position->setX(newPosition.getX());
    this->position->setY(newPosition.getY());
}

void Cell::setPosition(int pX, int pY) {
    this->position->setX(pX);
    this->position->setY(pY);
}

void Cell::setCellType(CellType newCellType) {
    this->cellType = newCellType;
}

void Cell::setContent(Content newContent) {
    this->content = newContent;
}

#endif
