
#include "Zombie.hpp"

Zombie::Zombie(): name("default")
{
    std::cout << this->name << " Zombie born" << std::endl;
}
Zombie::Zombie(std::string name):name(name)
{
    std::cout << name << " Zombie born" << std::endl;
}
Zombie::~Zombie()
{
    std::cout << this->name << " Zombie died" << std::endl;
}

void Zombie::annonce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}
