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

        // Signature
        mid.signForm(shrub);   // OK (sign 145)
        high.signForm(robo);   // OK (sign 72)
        high.signForm(pardon); // OK (sign 25)

        // Exécution
        low.executeForm(shrub);   // échec (grade trop bas)
        mid.executeForm(shrub);   // OK (exec 137)

        mid.executeForm(robo);    // échec (45)
        high.executeForm(robo);   // OK

        high.executeForm(pardon); // OK (exec 5)

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}