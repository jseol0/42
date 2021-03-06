/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:19:56 by jseol             #+#    #+#             */
/*   Updated: 2022/07/15 11:11:51 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: mWeapon(NULL), mName(name)
{

}

void	HumanB::attack(void)
{
	std::cout << mName << " attacks with his " << mWeapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& Weapon)
{
	mWeapon = &Weapon;
}
