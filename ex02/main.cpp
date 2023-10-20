#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    AForm* csf = new ShrubberyCreationForm( "Shrubbery" );
    AForm* rrf = new RobotomyRequestForm( "Roboto" );
    AForm* ppf = new PresidentialPardonForm( "Pardon" );

    try
    {
        Bureaucrat b( "Hamza", 145 );

        csf->beSigned( b );
         std::cout << std::endl;

        rrf->beSigned( b );
         std::cout << std::endl;

        ppf->beSigned( b );
        std::cout << std::endl;

        b.executeForm( *csf );
         std::cout << std::endl;

        b.executeForm( *rrf );
         std::cout << std::endl;

        b.executeForm( *ppf );

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
