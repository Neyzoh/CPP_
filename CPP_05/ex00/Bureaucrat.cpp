#include "Bureaucrat.hpp"

// --- Vérification du grade ---

void Bureaucrat::checkGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

// --- Forme canonique orthodoxe ---

Bureaucrat::Bureaucrat()
    : name_("default"), grade_(150) {
    // grade 150 est valide, pas d'exception
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name_(name), grade_(grade) {
    checkGrade(grade_);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_), grade_(other.grade_) {
    // copie simple
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        // name_ est const, on ne peut pas le changer
        grade_ = other.grade_;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    // rien à libérer
}

// --- Getters ---

std::string Bureaucrat::getName() const {
    return name_;
}

int Bureaucrat::getGrade() const {
    return grade_;
}

// --- Modification du grade ---

void Bureaucrat::incrementGrade() {
    // améliorer le grade = diminuer la valeur numérique
    int newGrade = grade_ - 1;
    checkGrade(newGrade);
    grade_ = newGrade;
}

void Bureaucrat::decrementGrade() {
    // empirer le grade = augmenter la valeur numérique
    int newGrade = grade_ + 1;
    checkGrade(newGrade);
    grade_ = newGrade;
}

// --- Opérateur << ---

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}