/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:09:41 by jseol             #+#    #+#             */
/*   Updated: 2022/08/09 21:32:10 by jseol            ###   ########.fr       */
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

char Converter::toChar(double d)
{
	char value = static_cast<char>(d);
	if (std::isinf(d) || std::isnan(d))
		throw std::string("impossible");
	else if (value < 32 || value > 126)
		throw std::string("Non displayable");
	return (value);
}

int Converter::toInt(double d)
{
	int value = static_cast<int>(d);
	if (std::isinf(d) || std::isnan(d) || d > INT_MAX || d < INT_MIN)
		throw std::string("impossible");
	return (value);
}

float Converter::toFloat(double d)
{
	return (static_cast<float>(d));
}

double Converter::toDouble(double d)
{
	return (static_cast<double>(d));
}

const char *Converter::CantConvert::what() const throw()
{
	return ("Invalid format");
}