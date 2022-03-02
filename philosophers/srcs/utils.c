/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:44:26 by jaeyu             #+#    #+#             */
/*   Updated: 2022/02/24 22:03:18 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	while ((9 <= s[i] && s[i] <= 13) || s[i] == ' ')
		i++;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	ret = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret *= 10;
		ret += (s[i] - '0') * sign;
		i++;
	}
	return (ret);
}

long	get_time(struct timeval start)
{
	struct timeval	cur;
	long			sec;
	long			micro_sec;
	long			ret;

	gettimeofday(&cur, NULL);
	sec = cur.tv_sec - start.tv_sec;
	micro_sec = cur.tv_usec - start.tv_usec;
	ret = (sec * (long)1000) + (micro_sec / 1000);
	return (ret);
}

int	is_valid_arg(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 5 || argc > 6)
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
