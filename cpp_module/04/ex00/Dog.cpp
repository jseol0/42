/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:37:43 by jseol             #+#    #+#             */
/*   Updated: 2022/08/03 12:58:54 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] Default constructor" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << "[Dog] Copy constructor " << std::endl;
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	std::cout << "[Dog] assignment operator" << std::endl;
	Animal::operator=(rhs);

	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "[Dog]: Woof! Woof!" << std::endl;
}