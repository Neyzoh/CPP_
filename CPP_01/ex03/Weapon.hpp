#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string type);
    ~Weapon(void);
    void setType(std::string type); 
    const std::string& getType(void) const;
};

#endif

