/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:21:12 by elim              #+#    #+#             */
/*   Updated: 2021/10/23 16:19:12 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	check_range(unsigned long long ret, int sign)
{
	if (ret > LLONG_MAX && sign == 1)
		return (-1);
	if (ret > LLONG_MAX - 1 && sign == -1)
		return (0);
	return (ret * sign);
}

int	ft_atoi(const char *str)
{
	size_t					i;
	unsigned long long		ret;
	int						sign;

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
