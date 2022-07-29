/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:20:55 by jseol             #+#    #+#             */
/*   Updated: 2022/07/29 00:39:38 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	mHitPoints = 100;
	mEnergyPoints = 50;
	mAttackDamage = 20;
	std::cout << "[ScavTrap] default constructor " << mName << " called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	mHitPoints = 100;
	mEnergyPoints = 50;
	mAttackDamage = 20;
	std::cout << "[ScavTrap] string constructor " << mName << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	*this = other;
	std::cout << "[ScavTrap] coppy constructor " << mName << " called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] destructor " << mName << " called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	ClapTrap::operator=(rhs);
	std::cout << "[ScavTrap] assignment operator overloading" << std::endl;

	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (mEnergyPoints == 0)
		std::cout << "[ScavTrap] " << mName << "'s energy point is not enough" << std::endl;
	else
	{
		mEnergyPoints--;
		std::cout << "[ScavTrap] " << mName << " attacks " << target << ", causing " << mAttackDamage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] " << mName << " have entered in Gate keeper mode" << std::endl;
}