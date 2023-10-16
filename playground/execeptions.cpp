#include <iostream>
#include <cmath>

// *Uncaught exceptions

// double sqrtt( double x )
// {
//     if ( x < 0.0 )
//         throw "Error";
//     return ( sqrt( x ) );
// }

// int main()
// {
//     std::terminate();
//     double x = -1.1;

//     std::cout << "The sqrt of x: " << sqrtt( x ) << std::endl;
// }

// * catch-all handler

// double sqrtt( double x )
// {
//     if ( x < 0.0 )
//         throw "Error";
//     return ( sqrt( x ) );
// }

// int main()
// {
//     double x = -1.1;
//     try
//     {
//         x = sqrtt( x );
//         std::cout << "The sqrt of x: " << x << std::endl;
//     }
//     catch( ... )
//     {
//         std::cerr << "Error\n";
//     }
    // ? Best practice:  if your program uses exceptions, consider using a catch-all handler in main, to help ensure orderly behavior when an unhandled exception occurs. Also consider disabling the catch-all handler for debug builds, to make it
    //?                  easier to identify how unhandled exceptions are occurring.
// }

// * When constructors fail : the destructor doesn't called ~A() but still the member attribute cleaned up ~Member()

// class Member
// {
// public:
//     Member() { std::cerr << "Calling Member()\n"; }
//     ~Member() { std::cerr << "Calling ~Member()\n"; }
// };

// class A
// {
// private:
//     int x;
//     Member member;
// public:
//     A( int a_x ) : x ( a_x )
//     {
//         std::cerr << "Calling A()\n";
//         if ( x <= 0 )
//             throw -1;
//         // exit(1);
//     }
    
//     ~A() { std::cerr << "Calling ~A()\n"; }

// };

// int main()
// {

//     try
//     {
//         A a( 0 );
//     }
//     catch( ... )
//     {
//         std::cerr << "Error" << '\n';
//     }

// }

// * Exception classes

class Exec
{
private:
    std::string err;
public:
    Exec( const std::string error ) : err ( error ) {}

    const std::string& what() const { return ( err ); }
};

class A
{
private:
    int arr[ 2 ];
public:
    A() { arr[ 0 ] = 0; arr[ 1 ] = 1;  }
    
    const int& getInt( int idx ) const
    {
        if ( idx < 0 || idx > 1 )
            throw Exec( "Index out of range" );
        return ( arr[ idx ] );
    }
};

int main()
{

    A arr;

    try
    {
        std::cout << arr.getInt( -1 ) << std::endl;
    }
    catch( const Exec& e )
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}