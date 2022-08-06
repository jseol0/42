/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:00:26 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 13:30:01 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	Bureaucrat jseol("jseol", 42);

	Form secretForm("secretForm", 10, 10);
	std::cout << secretForm << std::endl;
	
	Form nomalForm("nomalForm", 120, 120);
	std::cout << nomalForm << std::endl;

	std::cout << std::endl;

	jseol.signForm(secretForm);
	jseol.signForm(nomalForm);

	std::cout << std::endl;

	std::cout << secretForm << std::endl;
	std::cout << nomalForm << std::endl;

	return 0;
}