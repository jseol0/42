/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:28:35 by jseol             #+#    #+#             */
/*   Updated: 2022/08/13 22:59:58 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void)
{				  
	std::cout << "============= default test =============" << std::endl;
	Array<int> intArr(10);

	for (unsigned i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";

	std::cout << std::endl;

	for (unsigned i = 0; i < intArr.size(); i++)
		intArr[i] = i + 1;

	for (unsigned i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";

	std::cout << "\n\n============= const read test =============" << std::endl;
	const Array<float> constArr(5);

	for (unsigned int i = 0; i < constArr.size(); i++)
	{
		std::cout << constArr[i] << " ";
	}

	std::cout << "\n\n============= copy test =============" << std::endl;
	Array<std::string> list(2);

	list[0] = "42";
	list[1] = "seoul";

	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << "list[" << i << "] = " << list[i] << std::endl;

	Array<std::string> copyList(list);

	copyList[1] = "paris";

	for (unsigned int i = 0; i < copyList.size(); i++)
		std::cout << "copyList[" << i << "] = " << copyList[i] << std::endl;

	std::cout << "\n============= nullArr and exception test =============" << std::endl;
	try
	{
		Array<int> nullArr;
		std::cout << nullArr[0];
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}