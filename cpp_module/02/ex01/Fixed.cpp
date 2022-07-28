/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:57:25 by jseol             #+#    #+#             */
/*   Updated: 2022/07/28 12:06:22 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::mFractionBits = 8;

Fixed::Fixed()
	: mValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	mValue = (i << mFractionBits);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	mValue = roundf(f * (1 << mFractionBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	mValue = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (mValue);
}

void	Fixed::setRawBits(int const raw)
{
	mValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (float(mValue) / (1 << mFractionBits));
}

int		Fixed::toInt(void) const
{
	return (mValue >> mFractionBits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& rhs)
{
	os << rhs.toFloat();
	return (os);
}
