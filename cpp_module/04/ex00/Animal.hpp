/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:10:45 by jseol             #+#    #+#             */
/*   Updated: 2022/08/02 21:11:36 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();
		Animal&	operator=(const Animal& rhs);

		virtual void makeSound() const;
		std::string getType() const;

		protected:
			std::string type;
};

#endif