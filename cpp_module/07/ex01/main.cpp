/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:03:01 by jseol             #+#    #+#             */
/*   Updated: 2022/08/12 22:36:20 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::cout << "====== int Array =======" << std::endl;
	int arr1[] = {1, 2, 3, 4, 42};
	iter(arr1, 5, print);
	std::cout << std::endl;

	std::cout << "====== String Array =======" << std::endl;
	std::string arr2[] = {"jseol", "42", "seoul"};
	iter(arr2, 3, print);
	std::cout << std::endl;

	std::cout << "====== double Array =======" << std::endl;
	double arr3[] = {1.1, 2.2, 3.3, 4.4, 42.42};
	iter(arr3, 5, print);

	return (0);
}