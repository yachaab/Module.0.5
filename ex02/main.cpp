#include "AForm.hpp"
#include "Concret.hpp"

int main()
{
    try
    {
        Bureaucrat b( "Hamza", 1 );
        AForm* a = new Concrete() ;
        AForm* b = new Concrete() ;

        *b = *a;
        //std::cout  << *a << std::endl << std::endl;

        delete a;
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