/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:35:54 by jseol             #+#    #+#             */
/*   Updated: 2022/07/15 13:40:18 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char const *argv[])
{
	if (argc != 4) {
		std::cout << "Error : Invaild input ./replace [FILE NAME] [FIND STRING] [REPLACE STRING]" << std::endl;
		exit(1);
	}
	else if (std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty()) {
		std::cout << "Error : Arguments must not be empty." << std::endl;
		exit(1);
	}
	else {
		std::ifstream input_fstrm;
		input_fstrm.open(argv[1]);
		if(!input_fstrm.is_open()) {
			std::cout << "Error : Cannot find file." << std::endl;
			exit(1);
		}

		std::ofstream output_fstrm;
		output_fstrm.open(std::string(argv[1])+".replace");

		std::string	line;
		while (!input_fstrm.eof())
		{
			std::getline(input_fstrm, line);
			std::size_t find_str = line.find(argv[2]);
			if (find_str != std::string::npos) {
				output_fstrm << line.substr(0, find_str);
				output_fstrm << argv[3];
				line = line.substr(find_str + std::string(argv[2]).length());
				output_fstrm << line;
			}
			else
				output_fstrm << line;
			if (!input_fstrm.eof())
				output_fstrm << std::endl;
		}
		input_fstrm.close();
		output_fstrm.close();
	}
	return (0);
}
