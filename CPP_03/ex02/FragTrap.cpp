#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hit = 100;
    this->energy = 100;
    this->attack_dmg = 30;
    std::cout << "ScavTrap " << this->name << "FragTrap constructor called" << std::endl;
}
FragTrap::~FragTrap()
{
}
void FragTrap::attack(const std::string& target)
{
    if (this->hit <= 0 || this->energy <= 0)
    {
        std::cout << "Cannot attack" << std::endl;
        return ;
    }
   std::cout << "Fragrap " << this->name << " attacks " << target <<xor
    ", causing " << this->attack_dmg << " points of damage!" << std::endl;
    this->energy--;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap" << this->name << "requests high fives!" << std::endl;
}
