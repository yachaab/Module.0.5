#include "PresidentialPardonForm.hpp"

class PresidentialPardonForm::ExecuteFormFailException : public std::exception
{
private:
    const char* error;

public:
    ExecuteFormFailException( const char* msg ) : error ( msg ) {}

    virtual const char* what() const throw()
    {
        return ( error );
    }
};

PresidentialPardonForm::PresidentialPardonForm()
    :   AForm( "Default", false, 25, 5 )
{}

PresidentialPardonForm::PresidentialPardonForm( const std::string target )
    :   AForm( target, false, 25, 5 )
{}

PresidentialPardonForm::PresidentialPardonForm( const AForm& obj ) : AForm( obj ) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(  const AForm& lhs)
{
    return ( ( PresidentialPardonForm& ) AForm::operator=( lhs ) );
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute( Bureaucrat const & bureaucrat ) const
{
    if ( this->getSign() && bureaucrat.getGrade() <= this->getGrtef() )
    {
        std::cout << bureaucrat.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
    else
        throw ExecuteFormFailException( "Bureaucrat failed to execute the form" );
}