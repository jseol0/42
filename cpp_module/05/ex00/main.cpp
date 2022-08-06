/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:00:26 by jseol             #+#    #+#             */
/*   Updated: 2022/08/05 11:06:14 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "==== Test 1 ====" << std::endl;
	try
	{
		Bureaucrat jseol("jseol", 1);
		std::cout << jseol << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "==== Test 2 ====" << std::endl;
	try
	{
		Bureaucrat jseol("jseol", 1);
		std::cout << jseol << std::endl;
		
		std::cout << "> Increase grade of <jseol>" << std::endl;
		jseol.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "==== Test 3 ====" << std::endl;
	try
	{
		Bureaucrat jseol("jseol", 150);
		std::cout << jseol << std::endl;
		
		std::cout << "> decrease grade of <jseol>" << std::endl;
		jseol.decreaseGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}