/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:00:04 by jseol             #+#    #+#             */
/*   Updated: 2022/08/03 13:24:01 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[Animal] Default constructor" << std::endl;
	type = "Animal";
}

Animal::Animal(const Animal& other)
{
	std::cout << "[Animal] Copy constructor " << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "[Animal] Destructor" << std::endl;
}

Animal&	Animal::operator=(const Animal& rhs)
{
	std::cout << "[Animal] assignment operator" << std::endl;
	type = rhs.type;

	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "[Animal]: NO SOUND" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}

Brain *Animal::getBrain() 
{
	return NULL;
}