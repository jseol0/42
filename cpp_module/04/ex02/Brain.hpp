/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:17:53 by jseol             #+#    #+#             */
/*   Updated: 2022/08/03 13:34:42 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		virtual ~Brain();
		Brain& operator=(const Brain& rhs);

		void putIdea(int idx, char const *idea);
		std::string const &getIdea(int idx) const;

	private:
		std::string ideas[100];
};

#endif