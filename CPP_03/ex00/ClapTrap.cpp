#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(""), hit(10), energy(10), attack_dmg(0)
{
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit <= 0 || this->energy <= 0)
    {
        std::cout << "Cannot attack" << std::endl;
        return ;
    }
        std::cout << "ClapTrap" << this->name << "attacks" << target <<
        ", causing " << this->attack_dmg <<" points of damage! " << std::endl;
    this->energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit == 0)
    {
        std::cout << "Target already died" << std::endl;
        return ;
    }
    if (hit >= amount)
        hit -= amount;
    else
        hit = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit > 0 && energy > 0)
    {
        hit += amount;
        energy -= 1;
        std::cout << "ClapTrap " << this->name << "repairs itself, regains" << amount << "HP" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " cannot repair!" << std::endl;
}
