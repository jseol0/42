/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:32:37 by jseol             #+#    #+#             */
/*   Updated: 2022/08/10 14:07:12 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main(void)
{
	Data d1;
	Data d2("jseol", 1, 26);
	uintptr_t p1 = serialize(&d1);
	uintptr_t p2 = serialize(&d2);

	std::cout << &d1 << std::endl;
	std::cout << d1;
	print(p1);

	std::cout << &d2 << std::endl;
	std::cout << d2;
	print(p2);

	return (0);
}