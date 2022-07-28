/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:46:14 by jseol             #+#    #+#             */
/*   Updated: 2022/07/29 00:50:45 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	FragTrap	frag("FRAG");
	ScavTrap	scav("SCAV");

	std::cout << std::endl;

	frag.attack("SCAV");
	scav.takeDamage(0);
	scav.beRepaired(10);
	scav.guardGate();
	
	std::cout << std::endl;

	scav.attack("FRAG");
	frag.takeDamage(20);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << std::endl;

	return 0;
}