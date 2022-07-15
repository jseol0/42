/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:19:45 by jseol             #+#    #+#             */
/*   Updated: 2022/07/12 12:54:52 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		
		void	attack(void);
		void	setWeapon(Weapon& _weapon);

	private:
		Weapon*		mWeapon;
		std::string	mName;
};

#endif