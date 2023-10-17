#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat b( "Hamza", 137 );

        ShrubberyCreationForm sc( "Hamza" );

        ShrubberyCreationForm scc( "Youssef" );

        sc.beSigned( b );

        scc = sc;

        std::cout << sc << std::endl;

        std::cout << std::endl;

        std::cout << scc << std::endl;

        std::cout << std::endl;

        AForm* br = new ShrubberyCreationForm( "Hamza" );

        AForm* brr = new ShrubberyCreationForm( "Youssef" );
        
        br->beSigned( b );

        *brr = *br;

        std::cout << *br << std::endl;

        std::cout << std::endl;

        std::cout << *brr << std::endl;

        br->execute( b );

        delete br;
        delete brr;

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