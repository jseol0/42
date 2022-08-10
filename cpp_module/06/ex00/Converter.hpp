/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:09:38 by jseol             #+#    #+#             */
/*   Updated: 2022/08/11 00:23:02 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <cstdlib>
# include <climits>

class Converter
{
	public:
		Converter();
		Converter(const Converter& other);
		~Converter();

		Converter& operator=(const Converter& rhs);

		char toChar(double d);
		int toInt(double d);
		float toFloat(double d);
		double toDouble(double d);

		class CantConvert : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

bool	checkChar(const std::string& str);
void	cast_char(char *str);

#endif