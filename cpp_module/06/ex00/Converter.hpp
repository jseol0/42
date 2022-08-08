/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:09:38 by jseol             #+#    #+#             */
/*   Updated: 2022/08/08 22:53:26 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <cmath>
# include <limits>

class Converter
{
	public:
		Converter();
		Converter(const Converter& other);
		~Converter();

		Converter& operator=(const Converter& rhs);

		char toChar(double);
		int toInt(double);
		float toFloat(double);
		double toDouble(double);

		class CantConvert : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif