/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:46:51 by jseol             #+#    #+#             */
/*   Updated: 2022/07/29 00:36:59 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: mName("default"), mHitPoints(10), mEnergyPoints(10), mAttackDamage(0)
{
	std::cout << "[ClapTrap] default constructor " << mName << " called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: mName(name), mHitPoints(10), mEnergyPoints(10), mAttackDamage(0)
{
	std::cout << "[ClapTrap] string constructor " << mName << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "[ClapTrap] coppy constructor " << mName << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] destructor " << mName << " called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	mName = rhs.mName;
	mHitPoints = rhs.mHitPoints;
	mEnergyPoints = rhs.mEnergyPoints;
	mAttackDamage = rhs.mAttackDamage;
	std::cout << "[ClapTrap] assignment operator overloading" << std::endl;

	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (mEnergyPoints == 0)
		std::cout << "[ClapTrap] " << mName << "'s energy point is not enough" << std::endl;
	else if (mHitPoints == 0)
		std::cout << "[ClapTrap] " << mName << " is alreay dead" << std::endl;
	else
	{
		mEnergyPoints--;
		std::cout << "[ClapTrap] " << mName << " attacks " << target << ", causing " << mAttackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (mHitPoints <= amount)
	{
		mHitPoints = 0;
		std::cout << "[ClapTrap] " << mName << " died" << std::endl;
	}
	else if (mHitPoints == 0)
		std::cout << "[ClapTrap] " << mName << " is alreay dead" << std::endl;
	else
	{
		mHitPoints -= amount;
		std::cout << "[ClapTrap] " << mName << " has taken " << amount << " points of damage" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (mEnergyPoints == 0)
		std::cout << "[ClapTrap] " << mName << "'s energy point is not enough" << std::endl;
	else if (mHitPoints == 0)
		std::cout << "[ClapTrap] " << mName << " is revived" << std::endl;
	else
	{
		mEnergyPoints--;
		mHitPoints += amount;
		std::cout << "[ClapTrap] " << mName << " has been repaired of " << amount << " energy points" << std::endl;
	}
}
