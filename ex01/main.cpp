#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b( "Hamza", 10 );

        Form a ( "Form", false , 10, 25 );

        std::cout  << a << std::endl << std::endl;

        a.beSigned( b );

        std::cout << std::endl << a << std::endl;
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