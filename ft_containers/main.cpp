/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:57:42 by heryu             #+#    #+#             */
/*   Updated: 2022/11/05 13:25:09 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void	print_container_name(const std::string& name)
{
	std::cout << "\033[1;43m" << "\033[1;33m"
			<< "========================================\n"
			<< "========================================\n"
			<< "========================================\n"
			<< "========================================\n"
			<< "========================================\n"
			<< "\033[0m" << "\033[1;33m"
			<< "                 " << name << std::endl
			<< "\033[1;43m" << "\033[1;33m"
			<< "========================================\n"
			<< "========================================\n"
			<< "========================================\n"
			<< "========================================\n"
			<< "========================================\n"
			<< "\033[0m" << std::endl << std::endl;
}

void	print_title(const std::string& title)
{
	std::cout << "\033[1;44m" << "\033[1;37m" << "==================== "
		<< title << " ====================" << "\033[0m" << std::endl << std::endl;
}
void	print_interface(const std::string& title)
{
	std::cout << "\033[1;34m" << title << "\033[0m" << std::endl;
}

void	print_success(const std::string& message)
{
	std::cout << std::endl << "\033[1;42m" << "\033[1;37m" << "===>>> " << message << "\033[0m" << std::endl;
}

void	print_fail(const std::string& message)
{
	std::cout << std::endl << "\033[1;41m" << "\033[1;37m" << "===>>> " << message << "\033[0m" << std::endl;
}

void	print_clear(void)
{
	std::getchar();
	printf("\033[H\033[J");
}

void	test()
{
	test_vector();
	test_map();
	test_stack();
}

// main
int main(void)
{
	std::cout << "Please press enter key... ";

	test();

	while (1);

	return (0);
}
