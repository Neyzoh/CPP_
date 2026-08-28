#include "AForm.hpp"
#include "Bureaucrat.hpp"


void AForm::checkGrade(int grade) 
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void AForm::checkExecuteRequirements(Bureaucrat const & executor) const 
{
    if (!isSigned_)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExec_)
        throw GradeTooLowException();
}

AForm::AForm(): name_("default"), isSigned_(false),gradeToSign_(150), gradeToExec_(150) 
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec): name_(name), isSigned_(false),gradeToSign_(gradeToSign), gradeToExec_(gradeToExec) 
{
    checkGrade(gradeToSign_);
    checkGrade(gradeToExec_);
}

AForm::AForm(const AForm& other): name_(other.name_), isSigned_(other.isSigned_),gradeToSign_(other.gradeToSign_), gradeToExec_(other.gradeToExec_) 
{
}

AForm& AForm::operator=(const AForm& other) 
{
    if (this != &other)
        isSigned_ = other.isSigned_;
    return *this;
}

AForm::~AForm() 
{
}

std::string AForm::getName() const 
{
    return name_;
}

bool AForm::isSigned() const 
{
    return isSigned_;
}

int AForm::getGradeToSign() const 
{
    return gradeToSign_;
}

int AForm::getGradeToExec() const 
{
    return gradeToExec_;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    isSigned_ = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) 
{
    os << "Form " << f.getName() << ", signed: " << (f.isSigned() ? "yes" : "no")
       << ", gradeToSign: " << f.getGradeToSign()
       << ", gradeToExec: " << f.getGradeToExec();
    return os;
}