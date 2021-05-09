/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:28:53 by jseol             #+#    #+#             */
/*   Updated: 2021/03/13 17:28:38 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_program_name(char **argv)
{
	ft_putstr(argv[0]);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	(void)argc;
	ft_print_program_name(argv);
	return (0);
}
