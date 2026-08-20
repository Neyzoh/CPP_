#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Intern      someRandomIntern;
        Bureaucrat  boss("Boss", 1);

        AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        AForm* f4 = someRandomIntern.makeForm("unknown form", "Nobody");

        if (f1) {
            boss.signForm(*f1);
            boss.executeForm(*f1);
            delete f1;
        }

        if (f2) {
            boss.signForm(*f2);
            boss.executeForm(*f2);
            delete f2;
        }

        if (f3) {
            boss.signForm(*f3);
            boss.executeForm(*f3);
            delete f3;
        }

        if (f4) {
            // normalement NULL → ne doit pas arriver, mais on protège
            delete f4;
        }

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}