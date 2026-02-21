#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void annonce(void);
        void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name);
