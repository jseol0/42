/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:19:06 by jseol             #+#    #+#             */
/*   Updated: 2022/07/12 12:55:09 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
	: mWeapon(weapon), mName(name)
{

}

void	HumanA::attack(void)
{
	std::cout << mName << " attacks with his " << mWeapon.getType() << std::endl;
}