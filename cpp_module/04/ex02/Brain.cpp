/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:23:55 by jseol             #+#    #+#             */
/*   Updated: 2022/08/03 13:35:04 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] Default constructor" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "[Brain] Copy constructor" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "[Brain] Destructor" << std::endl;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	std::cout << "[Brain] assignment operator" << std::endl;
	unsigned long length = sizeof(ideas) / sizeof(ideas[0]);
	for (unsigned long i = 0; i < length; i++)
		ideas[i] = rhs.ideas[i];
	return (*this);
}

void	Brain::putIdea(int idx, char const *idea)
{
	ideas[idx] = idea;
}

std::string const &Brain::getIdea(int idx) const
{
	return (ideas[idx]);
}