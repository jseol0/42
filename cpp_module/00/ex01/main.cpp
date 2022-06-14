/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:38:51 by jseol             #+#    #+#             */
/*   Updated: 2022/05/28 11:11:00 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	command;

	while (true)
	{
		std::cout << "Input command(ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "EXIT" || command == "exit")
			break;
		else if (command == "ADD" || command == "add")
			pb.AddContact();
		else if (command == "SEARCH" || command == "search")
			pb.SearchContact();
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}