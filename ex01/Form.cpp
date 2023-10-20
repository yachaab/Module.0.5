#include "Form.hpp"

class Form::GradeTooHighException : public std::exception
{
private:
    const char* error;
public:
    GradeTooHighException() : error ( "Grade Too Hight" ) {}

    virtual const char* what() const throw()
    {
        return ( error );
    } 
};

class Form::GradeTooLowException : public std::exception
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

Form::Form() 
    :   name ( "default" ),
        signedForm ( false ),
        gradeRequiredToSignTheForm ( 25 ),
        gradeRequiredToExecuteTheForm ( 10 )
{}

Form::Form( std::string bName, bool sign, int grtsf, int grtef )
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

Form::Form( const Form& obj )
    :   name ( obj.name ),
        signedForm ( obj.signedForm ),
        gradeRequiredToSignTheForm ( obj.gradeRequiredToSignTheForm ),
        gradeRequiredToExecuteTheForm( obj.gradeRequiredToExecuteTheForm )
{}

Form& Form::operator=( const Form& lhs )
{
    signedForm = lhs.signedForm;
    return ( *this );
}

Form::~Form() {}

const std::string&  Form::getName()   const
{
    return ( name );
}

const bool&         Form::getSign()   const
{
    return ( signedForm );
}

const int&          Form::getGrtsf()  const
{
    return ( gradeRequiredToSignTheForm );
}

const int&          Form::getGrtef()  const
{
    return ( gradeRequiredToExecuteTheForm );
}

void Form::beSigned( const Bureaucrat& bureaucrat )
{
    //add try chatch block here please
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

std::ostream& operator<<( std::ostream& out, const Form& form )
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

