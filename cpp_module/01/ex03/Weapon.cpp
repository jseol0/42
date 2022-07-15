/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:20:03 by jseol             #+#    #+#             */
/*   Updated: 2022/07/12 12:55:04 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
	: mType(type)
{

}

void		Weapon::setType(std::string type)
{
	mType = type;
}

std::string	Weapon::getType(void)
{
	return (mType);
}