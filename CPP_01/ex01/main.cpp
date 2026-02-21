#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie *zombies;

    zombies = zombieHorde(8, "adal");
    for(int i = 0; i < 8; i++)
        zombies[i].annonce();
    delete[] zombies;
    return(0);
}