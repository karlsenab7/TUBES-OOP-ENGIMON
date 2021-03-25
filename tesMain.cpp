#include "src/Peta.hpp"
#include "src/Player.hpp"

int main(int argc, char const *argv[])
{
    Peta *p = new Peta();
    

    Player *player = new Player(); 

    player->moveLEFT();
    player->getPeta().showPeta();
    p->showLegend();
    return 0;
}
 