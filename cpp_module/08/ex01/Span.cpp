/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:22:41 by jseol             #+#    #+#             */
/*   Updated: 2022/08/15 23:34:55 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : n(0)
{

}

Span::Span(unsigned int n) : n(n)
{

}

Span::Span(const Span& other)
{
	*this = other;
}

Span::~Span()
{

}

Span&	Span::operator=(const Span& rhs)
{
	if (this == &rhs)
		return (*this);
	n = rhs.n;
	vec = rhs.vec;

	return (*this);
}

void	Span::addNumber(int num)
{
	if (vec.size() == n)
		throw std::runtime_error("Span is already full");
	vec.push_back(num);
}

void	Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	std::vector<int>::iterator iter = begin;
	
	while (iter != end)
	{
		if (vec.size() == n)
			throw std::runtime_error("Span is already full");
		vec.push_back(*iter);
		iter++;
	}
}

int		Span::shortestSpan(void) const
{
	if (vec.size() <= 1)
		throw std::runtime_error("Fewer stored");
	
	std::vector<int> copy = vec;
	std::sort(copy.begin(), copy.end());
	
	int min_diff = INT_MAX;
	int prev = *copy.begin();
	for (std::vector<int>::iterator iter = copy.begin() + 1; iter != copy.end(); iter++)
	{
		min_diff = std::min(min_diff, *iter - prev);
		prev = *iter;
	}

	return (min_diff);
}

int		Span::longestSpan(void) const
{
	if (vec.size() <= 1)
		throw std::runtime_error("Fewer stored");
	
	std::vector<int> copy = vec;
	std::sort(copy.begin(), copy.end());

	return (copy.back() - copy.front());
}