/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:37:41 by jseol             #+#    #+#             */
/*   Updated: 2022/08/03 13:57:40 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Cat] Default constructor" << std::endl;
	type = "Cat";
	mBrain = new Brain();
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << "[Cat] Copy constructor " << std::endl;
	mBrain = new Brain(*other.mBrain);
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor" << std::endl;
	delete mBrain;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	std::cout << "[Cat] assignment operator" << std::endl;
	Animal::operator=(rhs);
	mBrain = new Brain(*rhs.mBrain);

	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "[Cat]: Meow~ Meow~" << std::endl;
}

Brain *Cat::getBrain() 
{
	return (mBrain);
}