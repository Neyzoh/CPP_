#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0) 
        return(NULL);
    Zombie *zombiehorde = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombiehorde[i].setName(name);
    return(zombiehorde);
}