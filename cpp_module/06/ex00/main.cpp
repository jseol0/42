/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:09:35 by jseol             #+#    #+#             */
/*   Updated: 2022/08/09 21:32:11 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : Arguments" << std::endl;
		return (1);
	}

	double value;
	char *ptr;
	Converter converter;
	
	try
	{
		value = std::strtod(argv[1], &ptr);
		
		if (value == 0.0 && argv[1][0] != '-' &&
		argv[1][0] != '+' && !std::isdigit(argv[1][0]))
			throw Converter::CantConvert();
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
		return (1);
	}

	try
	{
		char c = converter.toChar(value);
		std::cout << "char : '" << c << "'" << std::endl;
	}
	catch (std::string &e)
	{
		std::cout << "char : " << e << std::endl;
	}

	try
	{
		int i = converter.toInt(value);
		std::cout << "int : " << i << std::endl;
	}
	catch (std::string &e)
	{
		std::cout << "int : " << e << std::endl;
	}

	float f = converter.toFloat(value);
	if (f - static_cast<int>(f) != 0)
		std::cout << "float : " << f << "f" << std::endl;
	else
		std::cout << "float : " << f << ".0f" << std::endl;

	double d = converter.toDouble(value);
	if (d - static_cast<int>(d) != 0)
		std::cout << "double : " << d << std::endl;
	else
		std::cout << "double : " << d << ".0" << std::endl;

	return (0);
}