/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:57:55 by jseol             #+#    #+#             */
/*   Updated: 2022/05/26 20:57:14 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

# define	TOTAL_WIDTH	45
# define	WIDTH		10

class	Contact
{
	public:
			Contact();
			~Contact();

			void				SetContact(void);
			void				DisplayBasicInfo(const unsigned int index);
			void				DisplayAllInfo();

	private:
			std::string			mFirstName;
			std::string			mLastName;
			std::string			mNickName;
			std::string			mPhoneNumber;
			std::string			mDarkestSecret;
};

#endif