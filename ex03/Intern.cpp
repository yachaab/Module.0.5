#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern( const Intern& obj ) { ( void ) obj; }

Intern& Intern::operator=( const Intern& rhs ) { ( void ) rhs; return ( *this ); }

Intern::~Intern() {}

int leget( const std::string& value )
{
	return ( value == "shrubbery creation" ) ? 1 :
	( value == "robotomy request" ) ? 2 :
	( value == "presidential pardon" ) ? 3 : 0;
}

AForm* Intern::makeForm( const std::string& form, const std::string& target )
{
	switch ( leget( form ) )
	{
	case 1:
		std::cout << "Intern creates " << form << std::endl;
		return ( new ShrubberyCreationForm( target ) );
	case 2:
		std::cout << "Intern creates " << form << std::endl;
		return ( new RobotomyRequestForm( target ) );
	case 3:
		std::cout << "Intern creates " << form << std::endl;
		return ( new PresidentialPardonForm( target ) );
	default:
		std::cout << "Intern can't make " << form << " form" << std::endl;
		return ( NULL );
	}
}