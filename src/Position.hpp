#ifndef __POSITION_HPP__
#define __POSITION_HPP__

class Position
{
private:
    int x;
    int y;
public:
    Position();
    Position(int pX, int pY);

    // getter
    int getX();
    int getY();

    // setter
    void setX(int pX);
    void setY(int pY);

};

Position::Position()
{
    this->x = 0;
    this->y = 0;
}

Position::Position(int pX, int pY)
{
    this->x = pX;
    this->y = pY;
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
