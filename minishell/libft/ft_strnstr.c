/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 00:40:35 by elim              #+#    #+#             */
/*   Updated: 2021/10/23 16:42:13 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	str_len;
	size_t	find_len;
	size_t	max;

	if (!*to_find)
		return ((char *)str);
	str_len = ft_strlen(str);
	find_len = ft_strlen(to_find);
	if (str_len < find_len || len < find_len)
		return (0);
	if (str_len > len)
		max = len;
	else
		max = str_len;
	while (max-- >= find_len)
	{
		if (!ft_memcmp(str, to_find, find_len))
			return ((char *)str);
		str++;
	}
	return (0);
}
