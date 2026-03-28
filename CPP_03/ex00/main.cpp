#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Bob");
    clap.attack("Zombie");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.takeDamage(15);
    return 0;
}
