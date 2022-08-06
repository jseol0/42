/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:40:45 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 17:53:49 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("shrubbery_creation", 145, 137)
{
	mTarget = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: Form(other)
{
	mTarget = other.mTarget;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: Form("shrubbery_creation", 145, 137)
{
	mTarget = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	Form::operator=(rhs);
	mTarget = rhs.mTarget;
	return (*this);
}

void ShrubberyCreationForm::action(void) const
{
	std::ofstream out(mTarget + "_shrubbery");
	
	out << "         |              " << std::endl;
	out << "        /|\\            " << std::endl;
	out << "       /*|O\\           " << std::endl;
	out << "      /*/|\\*\\         " << std::endl;
	out << "     /X/O|*\\X\\        " << std::endl;
	out << "    /*/X/|\\X\\*\\      " << std::endl;
	out << "   /O/*/X|*\\O\\X\\     " << std::endl;
	out << "  /*/O/X/|\\X\\O\\*\\   " << std::endl;
	out << " /X/O/*/X|O\\X\\*\\O\\  " << std::endl;
	out << "/O/X/*/O/|\\X\\*\\O\\X\\ " << std::endl;
	out << "        |X|             " << std::endl;
	out << "        |X|             " << std::endl;

	out.close();
}