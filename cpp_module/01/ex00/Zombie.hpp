/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:58:29 by jseol             #+#    #+#             */
/*   Updated: 2022/07/05 23:44:27 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	public:
			Zombie();
			Zombie(std::string name);
			~Zombie();
			void	announce(void);

	private:
			std::string mName;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif