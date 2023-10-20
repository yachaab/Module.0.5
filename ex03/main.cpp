#include "Intern.hpp"

int main()
{

    Intern in;
    AForm* scf = in.makeForm( "shrubbery creation", "SCF" );
    std::cout << std::endl;
    AForm* rrf = in.makeForm( "robotomy request", "RRF" );
    std::cout << std::endl;
    AForm* ppf = in.makeForm( "presidential pardon", "PPF" );
    try
    {
		Bureaucrat b( "Hamza", 2 );
        if ( scf )
        {
            std::cout << std::endl;
            scf->beSigned( b );
            b.executeForm( *scf );
        }

        if ( rrf )
        {
            std::cout << std::endl;
            rrf->beSigned( b );
            b.executeForm( *rrf );
        }

        if ( ppf )
        {
            std::cout << std::endl;
            ppf->beSigned( b );
            b.executeForm( *ppf );
        }
    }
    catch( const std::exception& e )
    {
        std::cerr << FRED( "Exception: " ) << e.what() << '\n';
    }
    catch( ... )
    {
        std::cerr << FRED( "unexpected error\n" );
    }

    delete scf;
    delete rrf;
    delete ppf;

    return (0);
}
