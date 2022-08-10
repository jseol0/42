/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:09:41 by jseol             #+#    #+#             */
/*   Updated: 2022/08/11 00:31:00 by jseol            ###   ########.fr       */
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
	float value = static_cast<float>(d);
	if (d > __FLT_MAX__ || d < -__FLT_MAX__)
		throw std::string("impossible");
	return (value);
}

double Converter::toDouble(double d)
{
	double value = static_cast<double>(d);
	if (d > __DBL_MAX__ || d < -__DBL_MAX__)
		throw std::string("impossible");
	return (value);
}

const char *Converter::CantConvert::what() const throw()
{
	return ("Invalid format");
}

bool	checkChar(const std::string& str)
{
	if (str == "-inf" || str == "+inf" || str == "inf" ||
		str == "-inff" || str == "+inff" || str == "inff")
		return(false);
	else if (str == "+nan" || str == "-nan" || str == "nan" ||
		str == "+nanf" || str == "-nanf" || str == "nanf")
		return (false);
	else if (str.size() == 1 && !isdigit(str[0]))
		return (true);
	return (false);
}

void	cast_char(char *str)
{
	char c = static_cast<char>(str[0]);
	std::cout << "char : '" << c << "'" << std::endl;

	int i = static_cast<int>(str[0]);
	std::cout << "int : " << i << std::endl;

	float f = static_cast<float>(str[0]);
	if (f - static_cast<int>(f) != 0)
		std::cout << "float : " << f << "f" << std::endl;
	else
		std::cout << "float : " << f << ".0f" << std::endl;

	double d = static_cast<double>(str[0]);
	if (d - static_cast<int>(d) != 0)
		std::cout << "double : " << d << std::endl;
	else
		std::cout << "double : " << d << ".0" << std::endl;
}