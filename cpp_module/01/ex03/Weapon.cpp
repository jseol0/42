/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:20:03 by jseol             #+#    #+#             */
/*   Updated: 2022/07/20 12:40:02 by jseol            ###   ########.fr       */
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

const & std::string	Weapon::getType(void)
{
	return (mType);
}
