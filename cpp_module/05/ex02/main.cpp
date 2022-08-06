/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:00:26 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 19:39:49 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm sc("home"); // sign(145), exec(137)
	Bureaucrat A("A", 100); 
	A.signForm(sc);
	A.executeForm(sc);

	std::cout << std::endl;
	
	RobotomyRequestForm rr("jseol"); // sign(72), exec(45)
	Bureaucrat B("B", 60);
	B.signForm(rr);
	B.executeForm(rr);

	std::cout << std::endl;
	
	PresidentialPardonForm pp("Dent");	// sign(25), exec(5)
	Bureaucrat C("C", 40);
	C.signForm(pp);
	C.executeForm(pp);

	return (0);
}