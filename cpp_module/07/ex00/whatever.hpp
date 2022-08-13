/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:26:16 by jseol             #+#    #+#             */
/*   Updated: 2022/08/12 22:22:15 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T& min(T& a, T& b)
{
	if (a < b)
		return (a);
	else if (a == b)
		return (b);
	else
		return (b);
}

template <typename T>
T& max(T& a, T& b)
{
	if (a > b)
		return (a);
	else if (a == b)
		return (b);
	else
		return (b);
}

#endif