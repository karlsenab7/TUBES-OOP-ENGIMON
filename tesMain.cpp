#include "src/Peta.hpp"
#include "src/Player.hpp"

int main(int argc, char const *argv[])
{
    Peta *p = new Peta();
    

    Player *player = new Player(); 

    Cell *c = new Cell(0,0, CellType::grassland, Content::player);
    p->setCell(0, 0, *c);

    p->showPeta();
    p->showLegend();
    return 0;
}
