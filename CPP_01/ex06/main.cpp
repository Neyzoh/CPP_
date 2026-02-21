#include "Harl.hpp"

int main(int ac, char **av) 
{
    Harl harl;
    if (ac == 2)
    {
        std::string complain = av[1];
        harl.complain(complain);
    }
    else
        std::cerr << "Invalid number of argument" << std::endl;

    return 0;
}
