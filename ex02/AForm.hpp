#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
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
    AForm();
    AForm( std::string, bool, int, int );
    AForm(  const AForm& );
    AForm& operator=(  const AForm& );
    virtual ~AForm();

    const std::string&  getName()   const;
    const bool&         getSign()   const;
    const int&          getGrtsf()  const;
    const int&          getGrtef()  const;

    void beSigned( const Bureaucrat& );
    virtual void execute(Bureaucrat const & ) const = 0;
};

std::ostream& operator<<( std::ostream& out, const AForm& form );

#endif