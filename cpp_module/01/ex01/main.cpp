/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:11:07 by jseol             #+#    #+#             */
/*   Updated: 2022/07/15 10:46:37 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde;
	int N = 3;

	horde = zombieHorde(N, "monster");
	for(int i=0; i<N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;

	return (0);
}
