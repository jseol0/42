/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:01:22 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/28 00:03:42 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

int main(int argc, char **argv)
{
	(void)argv;

	if (argc != 4 && argc != 5)
		ft_error("Too many input");
	return (0);
}