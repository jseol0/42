/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:38:27 by jseol             #+#    #+#             */
/*   Updated: 2022/07/13 00:40:19 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	stat[0].level = "debug";
	stat[0].ptr = &Harl::debug;
	stat[1].level = "info";
	stat[1].ptr = &Harl::info;
	stat[2].level = "warning";
	stat[2].ptr = &Harl::warning;
	stat[3].level = "error";
	stat[3].ptr = &Harl::error;
}

void Harl::complain(std::string level)
{
	int i = 0;
	while (i < 4)
	{
		if (stat[i].level == level)
		{
			(this->*(stat[i].ptr))();
			break;
		}
		i++;
	}
	if (i == 4)
		std::cout << level << std::endl;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}