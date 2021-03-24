#ifndef __ELEMENT_HPP__
#define __ELEMENT_HPP__

#include <iostream>
using namespace std;

class Element
{
private:
    string element;
public:
    Element(string);
    ~Element();

    string get_element();
    float getAdvantage(Element);
};

Element::Element(string el)
{
    this->element = el;
}

Element::~Element() {}

string Element::get_element()
{
    return this->element;
}

float Element::getAdvantage(Element el)
{
    string e1 = this->element;
    string e2 = el.get_element();

    int idxEl1 = -1;
    int idxEl2 = -1;

    if (e1 == "Fire")
        idxEl1 = 0;
    else if (e1 == "Water")
        idxEl1 = 1;
    else if (e1 == "Electric")
        idxEl1 = 2;
    else if (e1 == "Ground")
        idxEl1 = 3;
    else if (e1 == "Ice")
        idxEl1 = 4;
    
    if (e2 == "Fire")
        idxEl2 = 0;
    else if (e2 == "Water")
        idxEl2 = 1;
    else if (e2 == "Electric")
        idxEl2 = 2;
    else if (e2 == "Ground")
        idxEl2 = 3;
    else if (e2 == "Ice")
        idxEl2 = 4;

    float adva[5][5] = 
    {
        {1, 0, 1, 0.5, 2},
        {2, 1, 0, 1, 1},
        {1, 2, 1, 0, 1.5},
        {1.5, 1, 2, 1, 0},
        {0, 1, 0.5, 2, 1}
    };

    if (idxEl1 != -1 && idxEl2 != -1)
        return adva[idxEl1][idxEl2];
    else
        return -1;
}

#endif