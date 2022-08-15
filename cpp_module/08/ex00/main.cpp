/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:37:41 by jseol             #+#    #+#             */
/*   Updated: 2022/08/15 23:17:10 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}

	std::vector<int>::iterator iter = begin(vec);

	while (iter != end(vec))
	{
		std::cout << *iter++ << " ";
	}
	std::cout << std::endl;

	try
	{
		easyfind(vec, 4);
		std::cout << "easy find!" << std::endl;
		easyfind(vec, 8);
		std::cout << "easy find!" << std::endl;
		easyfind(vec, 12);
		std::cout << "easy find!" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	while (1);
	return (0);
}
