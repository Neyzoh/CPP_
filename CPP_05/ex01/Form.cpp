#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::checkGrade(int grade) 
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Form::Form(): name_("default"), isSigned_(false), gradeToSign_(150), gradeToExec_(150) 
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec): name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExec_(gradeToExec) 
{
    checkGrade(gradeToSign_);
    checkGrade(gradeToExec_);
}

Form::Form(const Form& other): name_(other.name_), isSigned_(other.isSigned_),gradeToSign_(other.gradeToSign_), gradeToExec_(other.gradeToExec_) 
{
}

Form& Form::operator=(const Form& other) 
{
    if (this != &other)
        isSigned_ = other.isSigned_;
    return *this;
}

Form::~Form() 
{
}

std::string Form::getName() const 
{
    return name_;
}

bool Form::isSigned() const 
{
    return isSigned_;
}

int Form::getGradeToSign() const 
{
    return gradeToSign_;
}

int Form::getGradeToExec() const 
{
    return gradeToExec_;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign_)
        throw GradeTooLowException();
    isSigned_ = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) 
{
    os << "Form " << f.getName() << ", signed: " << (f.isSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExec();
    return os;
}