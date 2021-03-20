#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <math.h>

class Point
{
private:
    int x;
    int y;
public:
    Point();
    Point(int pX, int pY);
    Point(const Point& cpyPoint);
    Point operator=(const Point& otherPoint);
    float Distance(Point pos2);

    

    // getter
    int getX();
    int getY();

    // setter
    void setX(int pX);
    void setY(int pY);

};

Point::Point()
{
    // default (0,0)
    this->x = 0;
    this->y = 0;
}

Point::Point(int pX, int pY)
{
    // membuat point (pX, pY)
    this->x = pX;
    this->y = pY;
}

Point::Point(const Point& cpyPoint) {
    this->x = cpyPoint.x;
    this->y = cpyPoint.y;
}

Point Point::operator=(const Point& otherPoint) {
    this->x = otherPoint.x;
    this->y = otherPoint.y;
    return *this;
}

float Point::Distance(Point pos2) {
    float jarakX = (this->x - pos2.getX()) * (this->x - pos2.getX());
    float jarakY = (this->y - pos2.getY()) * (this->y - pos2.getY());
    float distance = sqrt(jarakX + jarakY);
    return distance;
}

int Point::getX() {
    return this->x;
}

int Point::getY() {
    return this->y;
}

void Point::setX(int pX) {
    this->x = pX;
}

void Point::setY(int pY) {
    this->y = pY;
}

#endif
