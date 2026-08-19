#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <ostream>

// Forward declaration de Form (nécessaire car on l'utilise dans signForm)
class Form;

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "GradeTooHighException";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "GradeTooLowException";
        }
    };

    // Forme canonique
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Modification du grade
    void incrementGrade();
    void decrementGrade();

    // Fonction pour signer un formulaire (ex01)
    void signForm(Form& form);

private:
    const std::string name_;
    int grade_;

    static void checkGrade(int grade);
};

// Opérateur <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

// Déclaration de l'opérateur << pour Form (défini dans Form.cpp)
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif // BUREAUCRAT_HPP