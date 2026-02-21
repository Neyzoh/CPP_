
#include "Zombie.hpp"

Zombie::Zombie(): name("")
{
    std::cout << this->name << " Zombie born" << std::endl;
}
Zombie::~Zombie()
{
    std::cout << this->name << " Zombie died" << std::endl;
}
void Zombie::setName(std::string name)
{
    this->name = name;
}

void Zombie::annonce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}
