/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:17:22 by jseol             #+#    #+#             */
/*   Updated: 2022/08/15 23:36:56 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	std::cout << "========== subject test ==========" << std::endl;
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "========== execption test ==========" << std::endl;
	Span sp2 = Span(3);

	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		sp2.addNumber(10);
		std::cout << "addNumber success" << std::endl;
		sp2.addNumber(5);
		std::cout << "addNumber success" << std::endl;
		sp2.addNumber(3);
		std::cout << "addNumber success" << std::endl;
		sp2.addNumber(1);
		std::cout << "addNumber success" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << std::endl;

	std::cout << "========== iterator test ==========" << std::endl;
	Span sp3 = Span(10000);

	std::vector<int> vec;
	for (int i = 0; i < 10000; i++)
	{
		vec.push_back(i + 1);
	}

	sp3.addNumber(vec.begin(), vec.end());

	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	return (0);
}