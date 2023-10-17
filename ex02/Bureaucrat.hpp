#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define FRED(x) KRED x RST

#include <iostream>
#include <exception>
#include <fstream>
class Bureaucrat
{
private:
    std::string const name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat( const std::string, int );
    Bureaucrat(  const Bureaucrat& );
    Bureaucrat& operator=(  const Bureaucrat& );
    ~Bureaucrat();

    class GradeTooHighException;
    class GradeTooLowException;

    const std::string& getName() const;
    const int& getGrade() const;
    void increment();
    void decrement();

    void signedForm( bool , const std::string& ) const;
};

std::ostream& operator<<( std::ostream& out, const Bureaucrat& bureaucrat );

#endif