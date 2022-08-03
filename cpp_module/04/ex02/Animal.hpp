/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:10:45 by jseol             #+#    #+#             */
/*   Updated: 2022/08/03 23:22:28 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();
		Animal&	operator=(const Animal& rhs);

		virtual void makeSound() const = 0;
		std::string getType() const;
		virtual Brain *getBrain();

		protected:
			std::string type;
};

#endif