#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>
#include <ostream>

// On inclut Bureaucrat.hpp pour pouvoir prendre un Bureaucrat en paramètre
#include "Bureaucrat.hpp"

class Form {
public:
    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Form::GradeTooHighException";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Form::GradeTooLowException";
        }
    };

    // Forme canonique orthodoxe
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // Getters
    std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    // Fonctions membres
    void beSigned(const Bureaucrat& bureaucrat);

private:
    const std::string name_;
    bool isSigned_;
    const int gradeToSign_;
    const int gradeToExec_;

    static void checkGrade(int grade);
};

// Opérateur <<
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // FORM_HPP