#ifndef __Position_HPP__
#define __Position_HPP__

#include <math.h>

class Position
{
private:
    int x;
    int y;
public:
    Position();
    Position(int pX, int pY);
    Position(const Position& cpyPosition);
    Position operator=(const Position& otherPosition);
    float Distance(Position pos2);

    

    // getter
    int getX();
    int getY();

    // setter
    void setX(int pX);
    void setY(int pY);

};

Position::Position()
{
    // default (0,0)
    this->x = 0;
    this->y = 0;
}

Position::Position(int pX, int pY)
{
    // membuat Position (pX, pY)
    this->x = pX;
    this->y = pY;
}

Position::Position(const Position& cpyPosition) {
    this->x = cpyPosition.x;
    this->y = cpyPosition.y;
}

Position Position::operator=(const Position& otherPosition) {
    this->x = otherPosition.x;
    this->y = otherPosition.y;
    return *this;
}

float Position::Distance(Position pos2) {
    float jarakX = (this->x - pos2.getX()) * (this->x - pos2.getX());
    float jarakY = (this->y - pos2.getY()) * (this->y - pos2.getY());
    float distance = sqrt(jarakX + jarakY);
    return distance;
}

int Position::getX() {
    return this->x;
}

int Position::getY() {
    return this->y;
}

void Position::setX(int pX) {
    this->x = pX;
}

void Position::setY(int pY) {
    this->y = pY;
}

#endif
