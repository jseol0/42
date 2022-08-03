/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:37:43 by jseol             #+#    #+#             */
/*   Updated: 2022/08/03 13:41:03 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] Default constructor" << std::endl;
	type = "Dog";
	mBrain = new Brain();
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << "[Dog] Copy constructor " << std::endl;
	mBrain = new Brain(*other.mBrain);
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor" << std::endl;
	delete mBrain;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	std::cout << "[Dog] assignment operator" << std::endl;
	Animal::operator=(rhs);
	mBrain = new Brain(*rhs.mBrain);

	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "[Dog]: Woof! Woof!" << std::endl;
}

Brain *Dog::getBrain() 
{
	return (mBrain);
}