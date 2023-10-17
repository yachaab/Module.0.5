#include "RobotomyRequestForm.hpp"

class RobotomyRequestForm::ExecuteFormFailException : public std::exception
{
private:
    const char* error;

public:
    ExecuteFormFailException( const char* msg ) : error ( msg ) {}

    virtual const char* what() const throw()
    {
        return ( error );
    }
};

RobotomyRequestForm::RobotomyRequestForm()
    :   AForm( "Default", false, 72, 45 )
{}

RobotomyRequestForm::RobotomyRequestForm( const std::string target )
    :   AForm( target, false, 72, 45 )
{}

RobotomyRequestForm::RobotomyRequestForm( const AForm& obj ) : AForm( obj ) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(  const AForm& lhs)
{
    return ( ( RobotomyRequestForm& ) AForm::operator=( lhs ) );
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute( Bureaucrat const & bureaucrat ) const
{
    if ( this->getSign() && bureaucrat.getGrade() <= this->getGrtef() )
    {
        std::cout << "Start robotomized " << bureaucrat.getName() <<  std::endl;

        std::srand(std::time(0));

        if ( (int) rand() % 2 )
        {
			#if __APPLE__
            system("afplay  ~/Desktop/sound.wav");
			#elif __linux__
			system("ffplay ~/Desktop/sound.wav");
			#endif
            std::cout <<  bureaucrat.getName() << " has been robotomized ";
            std::cout << "successfully 50% of the time" << std::endl;
        }
        else
            std::cout <<  FRED( "robotomy failed" ) << std::endl;
    }
    else
        throw ExecuteFormFailException( "Bureaucrat failed to execute the form" );
}