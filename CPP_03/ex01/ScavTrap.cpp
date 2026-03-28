#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hit = 100;
    this->energy = 50;
    this->attack_dmg = 20;
    std::cout << "ScavTrap " << this->name << "ScavTrap constructor called" << std::endl;

}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << "destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hit <= 0 || this->energy <= 0)
    {
        std::cout << "Cannot attack" << std::endl;
        return ;
    }
   std::cout << "ScavTrap " << this->name << " attacks " << target <<xor
    ", causing " << this->attack_dmg << " points of damage!" << std::endl;
    this->energy--;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}