// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main0()
{
    try
    {
		Intern in;
        AForm* sc = in.makeForm( "robotomy request", "RR Form" );

		std::cout << "Sign: " << sc->getSign() << std::endl;


		Bureaucrat b( "Hamza", 45 );

		sc->beSigned( b );

		b.executeForm( *sc );

		std::cout << "Name: " << sc->getGrtsf() << std::endl;

    }
    catch( const std::exception& e )
    {
        std::cerr << FRED( "Exception: " ) << e.what() << '\n';
    }
    catch( ... )
    {
        std::cerr << FRED( "unexpected error\n" );
    }

    return (0);
}

int main()
{
    main0();
    // system( "leaks a.out" );
    return ( 0 );
}