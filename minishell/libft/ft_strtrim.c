/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:11:02 by elim              #+#    #+#             */
/*   Updated: 2021/10/28 15:42:30 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			break ;
		s1++;
		i++;
	}
	return (i);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t	i;

	if (!ft_strlen(s1))
		i = 0;
	else
		i = ft_strlen(s1) - 1;
	while (*s1)
		s1++;
	s1--;
	while (i > 0)
	{
		if (!ft_strchr(set, *s1))
			break ;
		s1--;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	ret_size;

	if (!s1)
		return (0);
	ret_size = find_end(s1, set) - find_start(s1, set) + 1;
	if (find_start(s1, set) >= find_end(s1, set))
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (ret_size + 1));
	if (!ret)
		return (0);
	ft_memcpy(ret, s1 + find_start(s1, set), ret_size);
	ret[ret_size] = 0;
	return (ret);
}
