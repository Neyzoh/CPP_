#include "Form.hpp"
#include "Bureaucrat.hpp"

// --- Vérification du grade ---

void Form::checkGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

// --- Forme canonique orthodoxe ---

Form::Form()
    : name_("default"), isSigned_(false), gradeToSign_(150), gradeToExec_(150) {
    // grades valides
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec)
    : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExec_(gradeToExec) {
    checkGrade(gradeToSign_);
    checkGrade(gradeToExec_);
}

Form::Form(const Form& other)
    : name_(other.name_), isSigned_(other.isSigned_),
      gradeToSign_(other.gradeToSign_), gradeToExec_(other.gradeToExec_) {
    // copie
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        // name_, gradeToSign_, gradeToExec_ sont const → on ne peut pas les changer
        // on peut seulement copier isSigned_
        isSigned_ = other.isSigned_;
    }
    return *this;
}

Form::~Form() {
    // rien à libérer
}

// --- Getters ---

std::string Form::getName() const {
    return name_;
}

bool Form::isSigned() const {
    return isSigned_;
}

int Form::getGradeToSign() const {
    return gradeToSign_;
}

int Form::getGradeToExec() const {
    return gradeToExec_;
}

// --- beSigned ---

void Form::beSigned(const Bureaucrat& bureaucrat) {
    // Le bureaucrate doit avoir un grade >= gradeToSign
    // (rappel : 1 est meilleur que 2, donc "grade plus haut" = valeur plus petite)
    if (bureaucrat.getGrade() > gradeToSign_) {
        // grade du bureaucrate trop "bas" (valeur trop grande)
        throw GradeTooLowException();
    }
    isSigned_ = true;
}

// --- Opérateur << ---

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName()
       << ", signed: " << (f.isSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExec();
    return os;
}