#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void Bureaucrat::checkGrade(int grade) 
{
    if (grade < 1) 
        throw GradeTooHighException();
    if (grade > 150) 
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(): name_("default"), grade_(150) 
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name), grade_(grade) 
{
    checkGrade(grade_);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name_(other.name_), grade_(other.grade_) 
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
    if (this != &other) 
        grade_ = other.grade_;
    return *this;
}

Bureaucrat::~Bureaucrat() 
{
}


std::string Bureaucrat::getName() const 
{
    return name_;
}

int Bureaucrat::getGrade() const 
{
    return grade_;
}

void Bureaucrat::incrementGrade() 
{
    int newGrade = grade_ - 1;
    checkGrade(newGrade);
    grade_ = newGrade;
}

void Bureaucrat::decrementGrade()
{
    int newGrade = grade_ + 1;
    checkGrade(newGrade);
    grade_ = newGrade;
}

void Bureaucrat::signForm(Form& form) 
{
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) 
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}