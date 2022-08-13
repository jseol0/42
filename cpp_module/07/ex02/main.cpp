/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:28:35 by jseol             #+#    #+#             */
/*   Updated: 2022/08/13 12:08:16 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void)
{				  
	std::cout << "============= default test =============" << std::endl;
	Array<int> intArr(10);

	for (unsigned i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " "; // []연산자 오버로딩 테스트

	std::cout << std::endl;

	for (unsigned i = 0; i < intArr.size(); i++)
		intArr[i] = i + 1;

	for (unsigned i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << " ";

	std::cout << "\n\n============= const read test =============" << std::endl;
	const Array<float> constArr(5);

	for (unsigned int i = 0; i < constArr.size(); i++)
	{
		std::cout << constArr[i] << " "; // const 배열 [] 연산자 오버로딩 테스트
	}

	std::cout << "\n\n============= copy test =============" << std::endl;
	Array<std::string> list(2);

	list[0] = "42";
	list[1] = "seoul";

	for (unsigned int i = 0; i < list.size(); i++)
		std::cout << "list[" << i << "] = " << list[i] << std::endl;

	Array<std::string> copyList(list); // 복사 생성자로 copyList 배열 생성

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

	return 0;
}