#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Clap");
    ScavTrap scav("Scav");      // ← Test ordre construction
    scav.attack("Zombie");
    scav.guardGate();
    scav.takeDamage(30);        // ← Hérité de ClapTrap
    scav.beRepaired(20);        // ← Hérité aussi
    return 0;                   // ← Test destruction
}