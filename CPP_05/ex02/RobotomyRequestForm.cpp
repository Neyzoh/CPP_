#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target_("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target_(other.target_) {}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target_ = other.target_;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    checkExecuteRequirements(executor);

    std::cout << "* drilling noises *" << std::endl;

    std::srand(std::time(0)); // simple, même si pas parfait
    if (std::rand() % 2)
        std::cout << target_ << " has been robotomized successfully!"
                  << std::endl;
    else
        std::cout << "Robotomy on " << target_ << " failed." << std::endl;
}