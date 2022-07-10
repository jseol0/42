/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:11:12 by jseol             #+#    #+#             */
/*   Updated: 2022/07/10 01:06:18 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	std::ostringstream	oss;
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		oss << ( i + 1 );
		horde[i].set_name(name + "_" + oss.str());
		oss.str("");
	}
	return (horde);
}