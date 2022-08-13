/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:02:55 by jseol             #+#    #+#             */
/*   Updated: 2022/08/13 12:08:33 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	print(T const &data)
{
	std::cout << data << std::endl;
}

template <typename T>
void	iter(T* array, unsigned int len, void(*func)(T const &ref))
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}

#endif