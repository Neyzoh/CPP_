#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
public:
    void highFivesGuys(void);
    void attack(const std::string& target);
    FragTrap(std::string name); 
    ~FragTrap();
};
