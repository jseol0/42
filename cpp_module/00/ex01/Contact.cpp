/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:57:42 by jseol             #+#    #+#             */
/*   Updated: 2022/05/27 12:09:02 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void	Contact::SetContact(void)
{
	std::cout << "Input first name: "; std::getline(std::cin, mFirstName);
	std::cout << "Input last name: "; std::getline(std::cin, mLastName);
	std::cout << "Input nick name: "; std::getline(std::cin, mNickName);
	std::cout << "Input phone number: "; std::getline(std::cin, mPhoneNumber);
	std::cout << "Input darkest secret: "; std::getline(std::cin, mDarkestSecret);
}

void	Contact::DisplayBasicInfo(const unsigned int index)
{
	std::cout << "|" << std::setw(WIDTH) << index;
	if (mFirstName.size() > 10)
		std::cout << "|" << mFirstName.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(WIDTH) << mFirstName;

	if (mLastName.size() > 10)
		std::cout << "|" << mLastName.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(WIDTH) << mLastName;

	if (mNickName.size() > 10)
		std::cout << "|" << mNickName.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(WIDTH) << mNickName;
	std::cout << "|" << std::endl;
}

void	Contact::DisplayAllInfo(void)
{
	
}