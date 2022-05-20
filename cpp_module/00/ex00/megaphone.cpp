/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:15:20 by jseol             #+#    #+#             */
/*   Updated: 2022/05/12 19:15:24 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	str_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (isalpha(str[i]) && islower(str[i]))
			str[i] = toupper(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[i])
		{
			str_upper(argv[i]);
			std::cout << argv[i];
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}