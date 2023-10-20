#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern( const Intern& );
	Intern& operator=( const Intern& );
	~Intern();

	AForm* makeForm( const std::string&, const std::string& );
};


#endif