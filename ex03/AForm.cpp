#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception
{
private:
    const char* error;
public:
    GradeTooHighException() : error ( "Grade Too High" ) {}

    virtual const char* what() const throw()
    {
        return ( error );
    } 
};

class AForm::GradeTooLowException : public std::exception
{
private:
    const char* error;
public:
    GradeTooLowException() : error ( "Grade Too Low" ) {}

    virtual const char* what() const throw()
    {
        return ( error );
    }
};

AForm::AForm() 
    :   name ( "default" ),
        signedForm ( false ),
        gradeRequiredToSignTheForm ( 25 ),
        gradeRequiredToExecuteTheForm ( 10 )
{}

AForm::AForm( std::string bName, bool sign, int grtsf, int grtef )
    :   name ( bName ),
        signedForm ( sign ),
        gradeRequiredToSignTheForm ( grtsf ),
        gradeRequiredToExecuteTheForm( grtef )
{
    if ( gradeRequiredToSignTheForm < 1 || gradeRequiredToExecuteTheForm < 1 )
        throw GradeTooHighException();
    else if ( gradeRequiredToSignTheForm > 150 || gradeRequiredToExecuteTheForm > 150 )
        throw GradeTooHighException();
}

AForm::AForm( const AForm& obj )
    :   name ( obj.name ),
        signedForm ( obj.signedForm ),
        gradeRequiredToSignTheForm ( obj.gradeRequiredToSignTheForm ),
        gradeRequiredToExecuteTheForm( obj.gradeRequiredToExecuteTheForm )
{}

AForm& AForm::operator=( const AForm& lhs )
{
    signedForm = lhs.signedForm;
    return ( *this );
}

AForm::~AForm() {}

const std::string&  AForm::getName()   const
{
    return ( name );
}

const bool&         AForm::getSign()   const
{
    return ( signedForm );
}

const int&          AForm::getGrtsf()  const
{
    return ( gradeRequiredToSignTheForm );
}

const int&          AForm::getGrtef()  const
{
    return ( gradeRequiredToExecuteTheForm );
}

void AForm::beSigned( const Bureaucrat& bureaucrat )
{
    try
    {
        if ( bureaucrat.getGrade() <= gradeRequiredToSignTheForm )
        {
            signedForm = true;
            bureaucrat.signedForm( signedForm, name );
        }
        else
        {
            bureaucrat.signedForm( signedForm, name );
            throw GradeTooLowException();
        }
    }
    catch( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }
}

std::ostream& operator<<( std::ostream& out, const AForm& form )
{
    std::string sign ( "unknown" );

    if ( form.getSign() )
        sign = "true";
    else
        sign = "false";

    out << "Form name: " << form.getName() << std::endl;
    out << "Grade required to sign the form: " <<  form.getGrtsf() << std::endl;
    out << "Grade required to execute the form: " << form.getGrtef() << std::endl;
    out << "Form signed: " << sign;

    return ( out );
}

