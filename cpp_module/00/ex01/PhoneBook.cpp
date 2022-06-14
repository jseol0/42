/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:57:24 by jseol             #+#    #+#             */
/*   Updated: 2022/05/28 11:44:24 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: mCapacity(0), mCurrentIndex(0)
{

}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::AddContact(void)
{
	if (mCurrentIndex < MAX)
	{
		mContact[mCurrentIndex].SetContact();
		mCapacity++;
		mCurrentIndex++;
	}
	else
	{
		unsigned int	index = mCurrentIndex % 8;
		mContact[index].SetContact();
		mCurrentIndex++;
	}
}

void	PhoneBook::SearchContact(void)
{
	if (mCapacity == 0)
	{
		std::cout << "empty contact" << std::endl;
		return ;
	}
	DisplayBasicContact();
	SearchIndexContact();
}

void	PhoneBook::DisplayBasicContact(void)
{
	std::cout << std::right << "\033[32m";
	std::cout << std::setfill('-') << std::setw(TOTAL_WIDTH) << "" << std::setfill(' ') << std::endl;
	std::cout << "|" << std::setw(WIDTH) << "index";
	std::cout << "|" << std::setw(WIDTH) << "first_name";
	std::cout << "|" << std::setw(WIDTH) << "last_name";
	std::cout << "|" << std::setw(WIDTH) << "nick_name";
	std::cout << "|" << std::endl;
	std::cout << std::setfill('-') << std::setw(TOTAL_WIDTH) << "" << std::setfill(' ') << std::endl;
	for (unsigned int i = 0; i < mCapacity; ++i)
	{
		mContact[i].DisplayBasicInfo(i);
	}
	std::cout << std::setfill('-') << std::setw(TOTAL_WIDTH) << "" << std::setfill(' ') << std::endl;
	std::cout << std::right << "\033[0m";
}

void	PhoneBook::SearchIndexContact(void)
{
	while (true)
	{
		std::cout << "input index for more information(quit: q): ";
		std::string	index_string;
		std::getline(std::cin, index_string);

		int	index = index_string[0] - '0';
		if (index_string.size() > 1)
			std::cout << "invalid index" << std::endl;
		else if (index_string == "q")
		{
			std::cout << "\033[33m" << "quit search index" << "\033[0m" << std::endl;
			break ;
		}
		else if (0 <= index && index < (int)mCapacity)
				mContact[index].DisplayAllInfo();
		else
			std::cout << "invalid index" << std::endl;
	}
}