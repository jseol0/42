/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:45:25 by jseol             #+#    #+#             */
/*   Updated: 2022/07/04 22:06:00 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	zb_0;
	Zombie	zb_1(std::string("Police Officer"));
	Zombie	zb_2(std::string("Aide"));
	Zombie	*zb_3 = newZombie("Congressman");
	
	zb_0.announce();
	zb_1.announce();
	zb_2.announce();
	zb_3->announce();
	randomChump("⭐President⭐");
	delete zb_3;
	return 0;
}