#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main0()
{
    AForm* csf = new ShrubberyCreationForm( "Shrubbery" );
    AForm* rrf = new RobotomyRequestForm( "Roboto" );
    AForm* ppf = new PresidentialPardonForm( "Pardon" );

    try
    {
        Bureaucrat b( "Hamza", 137 );

        csf->beSigned( b );
        b.executeForm( *csf );

        // rrf->beSigned( b );
        // b.executeForm( *rrf );

        // ppf->beSigned( b );
        // b.executeForm( *ppf );

    }
    catch( const std::exception& e )
    {
        std::cerr << FRED( "Exception: " ) << e.what() << '\n';
    }
    catch( ... )
    {
        std::cerr << FRED( "unexpected error\n" );
    }

    delete csf;
    delete rrf;
    delete ppf;

    return (0);
}

int main()
{
    main0();
    system( "leaks a.out" );
    return ( 0 );
}