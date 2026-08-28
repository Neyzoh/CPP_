#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>
#include <ostream>

#include "Bureaucrat.hpp"

class Form {
public:
    class GradeTooHighException : public std::exception 
    {
    public:
        virtual const char* what() const throw() 
        {
            return "Form::GradeTooHighException";
        }
    };

    class GradeTooLowException : public std::exception 
    {
    public:
        virtual const char* what() const throw() 
        {
            return "Form::GradeTooLowException";
        }
    };

    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    void beSigned(const Bureaucrat& bureaucrat);

private:
    const std::string name_;
    bool isSigned_;
    const int gradeToSign_;
    const int gradeToExec_;

    static void checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif