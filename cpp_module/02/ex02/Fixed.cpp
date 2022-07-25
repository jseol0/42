/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:10:58 by jseol             #+#    #+#             */
/*   Updated: 2022/07/22 02:53:11 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::mFractionBits = 8;

Fixed::Fixed()
	: mValue(0)
{

}

Fixed::Fixed(const int i)
{
	mValue = (i << mFractionBits);
}

Fixed::Fixed(const float f)
{
	mValue = roundf(f * (1 << mFractionBits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::~Fixed()
{

}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	mValue = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->mValue > rhs.mValue);
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->mValue < rhs.mValue);
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->mValue >= rhs.mValue);
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->mValue <= rhs.mValue);
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->mValue == rhs.mValue);
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->mValue != rhs.mValue);
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed&	Fixed::operator++()		//전위
{
	this->mValue++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->mValue--;
	return (*this);
}

Fixed	Fixed::operator++(int)		//후위
{
	Fixed	tmp(*this);

	this->mValue++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->mValue--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed&	Fixed::max(Fixed& lhs, Fixed& rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
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