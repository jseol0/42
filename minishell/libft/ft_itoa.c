/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:17:57 by elim              #+#    #+#             */
/*   Updated: 2021/10/23 16:24:12 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_ret_len(int n)
{
	int		tmp;
	size_t	i;

	tmp = n;
	i = 0;
	while (tmp)
	{
		tmp /= 10;
		i++;
	}
	if (n < 0)
		return (i + 1);
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		sign;
	size_t	i;
	size_t	len;

	if (!n)
		return (ft_strdup("0"));
	sign = 1;
	if (n < 0)
		sign = -1;
	len = calc_ret_len(n);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	i = len - 1;
	while (n)
	{
		ret[i] = (n % 10) * sign + 48;
		n /= 10;
		i--;
	}
	if (sign == -1)
		ret[i] = '-';
	ret[len] = 0;
	return (ret);
}
