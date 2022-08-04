/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:28:45 by jseol             #+#    #+#             */
/*   Updated: 2022/08/04 12:56:03 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	//const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	//std::cout << meta->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	//meta->makeSound();

	std::cout << std::endl;

	delete i;
	delete j;
	//delete meta;

	return (0);
}
