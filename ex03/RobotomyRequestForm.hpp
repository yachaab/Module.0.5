#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <stdlib.h>
#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
protected:
    class ExecuteFormFailException;

public:
    RobotomyRequestForm();
    RobotomyRequestForm( const std::string );
    RobotomyRequestForm(  const AForm& );
    RobotomyRequestForm& operator=(  const AForm& );
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & ) const;
};

#endif