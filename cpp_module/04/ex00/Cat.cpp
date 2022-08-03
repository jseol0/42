/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:37:41 by jseol             #+#    #+#             */
/*   Updated: 2022/08/03 12:58:44 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Cat] Default constructor" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << "[Cat] Copy constructor " << std::endl;
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	std::cout << "[Cat] assignment operator" << std::endl;
	Animal::operator=(rhs);

	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "[Cat]: Meow~ Meow~" << std::endl;
}