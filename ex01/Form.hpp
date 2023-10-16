#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string   name;
    bool                signedForm;
    int const           gradeRequiredToSignTheForm;
    int const           gradeRequiredToExecuteTheForm;

protected:
    class GradeTooHighException;
    class GradeTooLowException;

public:
    Form();
    Form( std::string, bool, int, int );
    Form(  const Form& );
    Form& operator=(  const Form& );
    ~Form();

    const std::string&  getName()   const;
    const bool&         getSign()   const;
    const int&          getGrtsf()  const;
    const int&          getGrtef()  const;

    void beSigned( const Bureaucrat& );
};

std::ostream& operator<<( std::ostream& out, const Form& form );

#endif