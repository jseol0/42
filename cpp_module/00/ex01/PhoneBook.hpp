/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:57:37 by jseol             #+#    #+#             */
/*   Updated: 2022/05/26 20:48:34 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX	8

class PhoneBook
{
	public:
			PhoneBook();
			~PhoneBook();
			void	AddContact(void);
			void	SearchContact(void);
			void	DisplayBasicContact(void);
			void	SearchIndexContact(void);

	private:
			Contact			mContact[MAX];
			unsigned int	mCapacity;
};

#endif