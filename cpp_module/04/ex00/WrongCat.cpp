/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:17:55 by jseol             #+#    #+#             */
/*   Updated: 2022/08/03 12:59:15 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "[WrongCat] Default constructor" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	std::cout << "[WrongCat] Copy constructor " << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] Destructor" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "[WrongCat] assignment operator" << std::endl;
	WrongAnimal::operator=(rhs);

	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "[WrongCat]: Meow~ Meow~" << std::endl;
}