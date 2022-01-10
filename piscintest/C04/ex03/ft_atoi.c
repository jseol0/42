/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:23:49 by jseol             #+#    #+#             */
/*   Updated: 2021/03/11 14:31:36 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char str)
{
	if (str == ' ' || str == '\f' || str == '\n' || str == '\r'
			|| str == '\t' || str == '\v')
		return (1);
	else
		return (0);
}

int	ft_issign(char str)
{
	if (str == '-')
		return (-1);
	else if (str == '+')
		return (1);
	else
		return (0);
}

int	ft_isdigit(char str)
{
	if (str >= '0' && str <= '9')
	{
		return (1);
	}
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int i;
	int sign;
	int ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (ft_isspace(str[i]))
		i++;
	while (ft_issign(str[i]))
	{
		sign *= ft_issign(str[i]);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ret *= 10;
		ret += ((str[i] - 48) * sign);
		i++;
	}
	return (ret);
}
#include <stdio.h>
int main()
{
	printf("%d", ft_atoi("-2147483648"));
}
