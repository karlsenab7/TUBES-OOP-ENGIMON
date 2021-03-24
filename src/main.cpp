#include <iostream>
#include "GameManagement.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    GameManagement GM;
    
    GM.newGame();
    GM.run();

    return 0;
}
