#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat high("High", 1);
        Bureaucrat mid("Mid", 50);
        Bureaucrat low("Low", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm   robo("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;

        mid.signForm(shrub);   
        high.signForm(robo);   
        high.signForm(pardon); 

        low.executeForm(shrub);   
        mid.executeForm(shrub);

        mid.executeForm(robo);  
        high.executeForm(robo);

        high.executeForm(pardon); 

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}