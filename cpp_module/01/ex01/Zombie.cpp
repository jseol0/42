/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:11:10 by jseol             #+#    #+#             */
/*   Updated: 2022/07/10 01:13:09 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Default Constructor Call" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << mName << " has disappeared" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	mName = name;
}