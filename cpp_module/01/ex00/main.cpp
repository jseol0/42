/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:45:25 by jseol             #+#    #+#             */
/*   Updated: 2022/07/05 23:38:43 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	zb_0;
	Zombie	zb_1(std::string("Iron Man"));
	Zombie	zb_2(std::string("Thor"));
	Zombie	*zb_3 = newZombie("Hulk");
	
	zb_0.announce();
	zb_1.announce();
	zb_2.announce();
	zb_3->announce();
	randomChump("⭐Jseol⭐");
	delete zb_3;
	return 0;
}