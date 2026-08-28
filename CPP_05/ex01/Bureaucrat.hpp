#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <ostream>

class Form;

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception 
    {
    public:
        virtual const char* what() const throw() 
        {
            return "GradeTooHighException";
        }
    };

    class GradeTooLowException : public std::exception 
    {
    public:
        virtual const char* what() const throw() 
        {
            return "GradeTooLowException";
        }
    };

    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form& form);

private:
    const std::string name_;
    int grade_;

    static void checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif