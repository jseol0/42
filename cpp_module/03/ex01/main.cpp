/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:46:14 by jseol             #+#    #+#             */
/*   Updated: 2022/07/28 00:37:24 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap	clap("CLAP");
	ScavTrap	scav("SCAV");

	std::cout << std::endl;

	clap.attack("SCAV");
	scav.takeDamage(0);
	scav.guardGate();
	scav.beRepaired(10);
	
	std::cout << std::endl;

	scav.attack("CLAP");
	clap.takeDamage(20);
	scav.guardGate();
	clap.beRepaired(20);

	std::cout << std::endl;

	return 0;
}