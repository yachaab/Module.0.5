#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception
{
private:
    const char* error;

public:
    GradeTooHighException( const char* msg ) : error ( msg ) {}

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
    GradeTooLowException( const char* msg ) : error ( msg ) {}

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
    if ( gradeRequiredToSignTheForm < 1 )
        throw GradeTooHighException( "Grade required to sign the form out of range: too hight" );
    else if ( gradeRequiredToSignTheForm > 150 )
        throw GradeTooHighException( "Grade required to sign the form out of range: too low" );
    if ( gradeRequiredToExecuteTheForm < 1 )
        throw GradeTooHighException( "Grade required to execute the form out of range: too hight" );
     else if ( gradeRequiredToExecuteTheForm > 150 )
        throw GradeTooHighException( "Grade required to execute the form out of range: too low" );
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
    if ( bureaucrat.getGrade() <= gradeRequiredToSignTheForm )
    {
        signedForm = true;
        bureaucrat.signedForm( signedForm, name );
    }
    else
    {
        bureaucrat.signedForm( signedForm, name );
        throw GradeTooLowException( "Grade required to sign the form: too low" );
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

