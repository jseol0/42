/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:01:28 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 19:04:00 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("presidential_pardon", 25, 5)
{
	mTarget = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: Form(other)
{
	mTarget = other.mTarget;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: Form("presidential_pardon", 25, 5)
{
	mTarget = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	Form::operator=(rhs);
	mTarget = rhs.mTarget;
	return (*this);
}

void PresidentialPardonForm::action(void) const
{
	std::cout << "<" << mTarget << "> has been pardoned by Zafod Beeblebrox." << std::endl;
}