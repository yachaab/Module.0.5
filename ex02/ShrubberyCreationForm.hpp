#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
protected:
    class ExecuteFormFailException;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm( const std::string );
    ShrubberyCreationForm(  const AForm& );
    ShrubberyCreationForm& operator=(  const AForm& );
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & ) const;
};

#endif