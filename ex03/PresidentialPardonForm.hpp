#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
protected:
    class ExecuteFormFailException;

public:
    PresidentialPardonForm();
    PresidentialPardonForm( const std::string );
    PresidentialPardonForm(  const AForm& );
    PresidentialPardonForm& operator=(  const AForm& );
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & ) const;
};

#endif