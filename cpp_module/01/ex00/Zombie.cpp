/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:58:32 by jseol             #+#    #+#             */
/*   Updated: 2022/07/04 22:17:02 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie::Zombie()
// {

// }

// Zombie::Zombie(std::string name) : mName(name)
// {

// }

// Zombie::~Zombie()
// {
	
// }

// void	Zombie::announce(void)
// {
// 	 std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl;
// }

Zombie::Zombie()
{
	std::cout << "someone appeared!" << std::endl;
}

Zombie::Zombie( std::string name ) : mName(name)
{
	std::cout << mName;
	std::cout << " has appeared!" << std::endl;
}

Zombie::~Zombie()
{
	mName.empty() ?
		std::cout << "someone disappeared." << std::endl:
		std::cout << mName << " has disappeared." << std::endl;
	
}

void	Zombie::announce(void)
{
	mName.empty() ?
		std::cout << "Unknown" :
		std::cout << mName;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}