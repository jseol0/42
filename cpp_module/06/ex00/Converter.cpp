/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:09:41 by jseol             #+#    #+#             */
/*   Updated: 2022/08/08 23:03:54 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter()
{

}

Converter::Converter(const Converter& other)
{
	*this = other;
}

Converter::~Converter()
{

}

Converter &Converter::operator=(const Converter &rhs)
{
	if (this == &rhs)
		return (*this);
	return *this;
}

char Converter::toChar(double f)
{
	char value = static_cast<char>(f);
	if (std::isinf(f) || std::isnan(f))
		throw std::string("impossible");
	else if (value < 32 || value > 126)
		throw std::string("Non displayable");
	return (value);
}

int Converter::toInt(double f)
{
	int value = static_cast<int>(f);
	if (std::isinf(f) || std::isnan(f) || f > INT_MAX || f < INT_MIN)
		throw std::string("impossible");
	return (value);
}

float Converter::toFloat(double f)
{
	return (static_cast<float>(f));
}

double Converter::toDouble(double f)
{
	return (static_cast<double>(f));
}

const char *Converter::CantConvert::what() const throw()
{
	return ("Invalid format");
}