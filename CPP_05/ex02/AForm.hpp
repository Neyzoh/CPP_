#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include <ostream>

class Bureaucrat;

class AForm {
public:
    class GradeTooHighException : public std::exception 
    {
    public:
        virtual const char* what() const throw() 
        {
            return "AForm::GradeTooHighException";
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw() 
        {
            return "AForm::GradeTooLowException";
        }
    };
    class FormNotSignedException : public std::exception 
    {
    public:
        virtual const char* what() const throw() 
        {
            return "AForm::FormNotSignedException";
        }
    };

    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    void beSigned(const Bureaucrat& bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;

protected:
    static void checkGrade(int grade);
    void checkExecuteRequirements(Bureaucrat const & executor) const;

private:
    const std::string name_;
    bool              isSigned_;
    const int         gradeToSign_;
    const int         gradeToExec_;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif