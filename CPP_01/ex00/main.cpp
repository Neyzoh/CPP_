#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie *zombie1;

    zombie1 = newZombie("Toto");
    zombie1->annonce();
    delete zombie1;

    randomChump("Titi");
}