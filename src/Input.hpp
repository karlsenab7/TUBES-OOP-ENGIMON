#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include<iostream>
using namespace std;


class Input
{
private:
    string input;
public:
    Input();
    Input(const Input& i);
    ~Input();
    string getInput();
};

Input::Input()
{
}

Input::Input(const Input& i)
{
    this->input = i.input;
}

Input::~Input()
{
}

string Input::getInput()
{
    cout << ">>> ";
    cin >> input;

    return input;
}


#endif