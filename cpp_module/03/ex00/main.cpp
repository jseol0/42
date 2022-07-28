/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:46:14 by jseol             #+#    #+#             */
/*   Updated: 2022/07/27 11:12:12 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	ft("A");

	ft.attack("B");
	std::cout << std::endl;

	ft.takeDamage(1);
	ft.takeDamage(2);
	ft.takeDamage(3);
	std::cout << std::endl;

	ft.attack("B");
	ft.attack("B");
	ft.attack("B");
	ft.beRepaired(1);
	ft.beRepaired(1);
	ft.beRepaired(1);
	ft.beRepaired(1);
	ft.beRepaired(1);
	ft.beRepaired(1);
	ft.beRepaired(1);
	std::cout << std::endl;

	ft.takeDamage(10);
	std::cout << std::endl;

	return 0;
}