/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 04:54:16 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/23 05:20:59 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <limits.h>

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static long long	check_range(long long ret, int sign)
{
	if (ret > LLONG_MAX && sign == 1)
		return (-1);
	if (ret > LLONG_MAX - 1 && sign == -1)
		return (-1);
	return (ret * sign);
}

long long	ft_atoi_exit(const char *str)
{
	int			i;
	int			sign;
	long long	ret;

	i = 0;
	sign = 1;
	while (is_space(str[i]) && str[i])
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	ret = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (check_range(ret, sign));
}

int	check_digit(t_cmd *cmd)
{
	int	i;

	i = -1;
	if (cmd->token[1].cmd[0] == '-')
		i++;
	while (cmd->token[1].cmd[++i] != '\0')
	{
		if (ft_isdigit(cmd->token[1].cmd[i]) == 0)
		{
			if (cmd->exit_flag == 1)
				return (0);
		}
	}
	return (1);
}
