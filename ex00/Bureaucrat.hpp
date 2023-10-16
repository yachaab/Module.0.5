#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
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

    class GradeTooLowException;
    class GradeTooHighException;

    const std::string& getName() const;
    const int& getGrade() const;
    void increment();
    void decrement();
};

std::ostream& operator<<( std::ostream& out, const Bureaucrat& bureaucrat );

#endif