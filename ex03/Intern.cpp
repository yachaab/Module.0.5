#include "Intern.hpp"

class Intern::InternWrongFormNameException
{
private:
	const char* error;

public:
    InternWrongFormNameException( const char* msg ) : error ( msg ) {}

    virtual const char* what() const throw()
    {
        return ( error );
    }
};

Intern::Intern() {}

Intern::Intern( const Intern& obj ) { ( void ) obj; }

Intern& Intern::operator=( const Intern& rhs ) { ( void ) rhs; return ( *this ); }

Intern::~Intern() {}

int leget( const std::string& value )
{
	return ( value == "shrubbery creation" ) ? 1 :
	( value == "robotomy request" ) ? 2 : ( value == "presidential pardon" ) ? 3 : 0;
}

AForm* Intern::makeForm( const std::string& form, const std::string& target )
{
	switch ( leget( form ) )
	{
	case 1:
		return ( new ShrubberyCreationForm( target ) );
		break;
	case 2:
		return ( new RobotomyRequestForm( target ) );
		break;
	case 3:
		return ( new PresidentialPardonForm( target ) );
		break;
	default:
		throw InternWrongFormNameException( "Intern can't make this form" );
	}
}