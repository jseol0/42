/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:44:26 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/30 23:21:44 by jaeyu            ###   ########.fr       */
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

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_numeric(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_is_digit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n', c == '\v' \
		|| c == '\f' || c == '\r')
		return (1);
	else
		reuturn (0);
}

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	ret = 0;
	while (s[i] >= '0' || s[i] <= '9')
	{
		ret *= 10;
		ret += (s[i] - '0') * sign;
		i++;
	}
	return (ret);
}