/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:12:10 by jseol             #+#    #+#             */
/*   Updated: 2022/08/02 21:14:55 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();
		WrongAnimal&	operator=(const WrongAnimal& rhs);

		void makeSound() const;
		std::string getType() const;

		protected:
			std::string type;
};

#endif