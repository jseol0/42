/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:00:26 by jseol             #+#    #+#             */
/*   Updated: 2022/08/07 00:05:44 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Bureaucrat jseol("jseol", 1);
		Intern intern;
		Form *form;

		form = intern.makeForm("shrubbery_creation", "home");
		jseol.signForm(*form);
		jseol.executeForm(*form);
		delete form;

		std::cout << std::endl;

		form = intern.makeForm("robotomy_request", "jseol");
		jseol.signForm(*form);
		jseol.executeForm(*form);
		delete form;

		std::cout << std::endl;

		form = intern.makeForm("presidential_pardon", "Dent");
		jseol.signForm(*form);
		jseol.executeForm(*form);
		delete form;

		std::cout << std::endl;

		form = intern.makeForm("no_name", "test");
		jseol.signForm(*form);
		jseol.executeForm(*form);
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}