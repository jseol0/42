/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:54:46 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 18:09:55 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("robotomy_request", 72, 45)
{
	srand(time(NULL));

	mTarget = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: Form(other)
{
	srand(time(NULL));

	mTarget = other.mTarget;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: Form("robotomy_request", 72, 45)
{
	srand(time(NULL));

	mTarget = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	Form::operator=(rhs);
	mTarget = rhs.mTarget;
	return (*this);
}

void RobotomyRequestForm::action(void) const
{
	if (rand() % 2)
	{
		std::cout << "\"Drrrrrrr....\" " << mTarget << " : Success" << std::endl;
	}
	else
	{
		std::cout << "We failed to robotomize " << mTarget << " : fail" << std::endl;
	}
}