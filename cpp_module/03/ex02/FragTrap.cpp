/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 00:24:28 by jseol             #+#    #+#             */
/*   Updated: 2022/07/29 00:57:48 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
	mHitPoints = 100;
	mEnergyPoints = 100;
	mAttackDamage = 30;
	std::cout << "[FragTrap] default constructor " << mName << " called" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	mHitPoints = 100;
	mEnergyPoints = 100;
	mAttackDamage = 30;
	std::cout << "[FragTrap] string constructor " << mName << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	*this = other;
	std::cout << "[FragTrap] coppy constructor " << mName << " called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] destructor " << mName << " called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	ClapTrap::operator=(rhs);
	std::cout << "[FragTrap] assignment operator overloading" << std::endl;

	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] " << mName << " High Fives Guys!" << std::endl;
}