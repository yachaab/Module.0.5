#ifndef CONCRETE_HPP
#define CONCRETE_HPP

#include "AForm.hpp"

class Concrete : public AForm
{
public:
    Concrete() { std::cout << "Calling Concrete()\n"; };
    ~Concrete() { std::cout << "Calling ~Concrete()\n"; };
    void beSigned( const Bureaucrat& ) { std::cout << "Calling override\n"; }
};

#endif