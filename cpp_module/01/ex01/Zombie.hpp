/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:11:14 by jseol             #+#    #+#             */
/*   Updated: 2022/07/10 01:13:28 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>

class	Zombie
{
	public:
			Zombie();
			~Zombie();

			void	announce(void);
			void	set_name(std::string name);
			
	private:
			std::string mName;
};

Zombie*	zombieHorde(int N, std::string name);

#endif