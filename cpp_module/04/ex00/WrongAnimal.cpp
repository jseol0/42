/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:13:32 by jseol             #+#    #+#             */
/*   Updated: 2022/08/03 12:59:07 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal] Default constructor" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "[WrongAnimal] Copy constructor " << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] Destructor" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "[WrongAnimal] assignment operator" << std::endl;
	type = rhs.type;

	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal]: WrongAnimal SOUND" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}