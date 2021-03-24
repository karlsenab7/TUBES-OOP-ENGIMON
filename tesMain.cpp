#include "src/Peta.hpp"

int main(int argc, char const *argv[])
{
    Peta *p = new Peta(20,20);
    p->generatePeta();
    return 0;
}
