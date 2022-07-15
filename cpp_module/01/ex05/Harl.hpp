/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:38:23 by jseol             #+#    #+#             */
/*   Updated: 2022/07/13 00:23:03 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	typedef struct s_complain
	{
		std::string level;
		void(Harl::*ptr)(void);
	}	t_complain;

	public:
		Harl();

		void	complain(std::string level);

	private:
		t_complain	stat[4];

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif