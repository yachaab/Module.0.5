#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b( "Hamza", 149 );
        Bureaucrat a = b;
        // b.increment();
        a.decrement();

        std::cout << b << std::endl;
        std::cout << a << std::endl;
    }
    catch( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }
    catch( ... )
    {
        std::cerr << "unexpected error\n";
    }
    return (0);
}