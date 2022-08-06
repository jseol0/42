/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:30:36 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 10:58:53 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: mName("default"), mGrade(150)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: mName(other.mName), mGrade(other.mGrade)
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: mName(name), mGrade(grade)
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	mGrade = rhs.mGrade;
	
	return (*this);
}

const std::string Bureaucrat::getName(void) const
{
	return (mName);
}

int Bureaucrat::getGrade(void) const
{
	return (mGrade);
}

void Bureaucrat::increaseGrade(void)
{
	mGrade--;
	if (mGrade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade(void)
{
	mGrade++;
	if (mGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException : Grade too height");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException : Grade too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << "<" << bureaucrat.getName() << ">, bureaucrat grade <" << bureaucrat.getGrade()  << ">";
	return os;
}