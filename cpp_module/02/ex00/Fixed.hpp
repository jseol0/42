/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:34:01 by jseol             #+#    #+#             */
/*   Updated: 2022/07/20 15:04:47 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					mValue;
		static const int	mFractionBits;
};

#endif
