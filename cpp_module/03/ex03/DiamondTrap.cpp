/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:11:22 by jseol             #+#    #+#             */
/*   Updated: 2022/07/29 21:33:33 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(), ScavTrap(), FragTrap(), mName(ClapTrap::mName)
{
	ClapTrap::mName += "_clap_name";
	mEnergyPoints = ScavTrap::mEnergyPoints;
	std::cout << "[DiamondTrap] default constructor " << mName << " called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), mName(name)
{
	mEnergyPoints = ScavTrap::mEnergyPoints;
	std::cout << "[DiamondTrap] string constructor " << mName << " called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	*this = other;
	std::cout << "[DiamondTrap] coppy constructor " << mName << " called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] destructor " << mName << " called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &rhs)
{
	ScavTrap::operator=(rhs);
	mName = rhs.mName;
	std::cout << "[DiamondTrap] assignment operator overloading" << std::endl;

	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "[DiamondTrap] name is " << mName << " and ClapTrap name is " << ClapTrap::mName << std::endl;
}