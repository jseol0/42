/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:22:11 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 13:29:05 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: mName("default"), isSigned(false), mSignGrade(150), mExecuteGrade(150)
{

}

Form::Form(const Form& other)
	: mName(other.mName), isSigned(false), mSignGrade(other.mSignGrade), mExecuteGrade(other.mExecuteGrade)
{

}

Form::Form(std::string name, int signGrade, int executeGrade) : mName(name), isSigned(false), mSignGrade(signGrade), mExecuteGrade(executeGrade)
{
	if (mSignGrade < 1 || mExecuteGrade < 1)
		throw Form::GradeTooHighException();
	if (mSignGrade > 150 || mExecuteGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{

}

Form& Form::operator=(const Form& rhs)
{
	isSigned = rhs.isSigned;
	return (*this);
}

std::string Form::getName(void) const
{
	return (mName);
}

bool		Form::getIsSigned(void) const
{
	return (isSigned);
}

int			Form::getSignGrade(void) const
{
	return (mSignGrade);
}

int			Form::getExecuteGrade(void) const
{
	return (mExecuteGrade);
}

void		Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > mSignGrade)
		throw Form::GradeTooLowException();

	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException : Grade too height");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException : Grade too low");
}

std::ostream& operator<<(std::ostream& os , const Form& form)
{
	os << "Form<" << form.getName() << "> :  isSigned(" << form.getIsSigned() << "), signGrade(" << form.getSignGrade() << "), executeGrade(" << form.getExecuteGrade() << ")";
	return (os);
}