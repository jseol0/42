/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:34:54 by elim              #+#    #+#             */
/*   Updated: 2021/10/23 16:33:33 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	all_free(char **pp, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
		free(pp[i++]);
	free(pp);
}

static size_t	get_size(char const *s, char c)
{
	size_t	size;
	size_t	flag;

	size = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && !flag)
		{
			flag = 1;
			size++;
		}
		if (*s == c)
			flag = 0;
		s++;
	}
	return (size);
}

static char	**sub_n_free(char const *s, char c, char **pp, size_t j)
{
	size_t	i;
	int		pivot;

	i = 0;
	pivot = -1;
	while (i < ft_strlen(s) + 1)
	{
		if ((s[i] == c || !s[i]) && pivot != -1)
		{
			pp[j] = ft_substr(s, pivot, i - pivot);
			if (!pp[j])
			{
				all_free(pp, j);
				return (0);
			}
			j++;
			pivot = -1;
		}
		if (s[i] != c && pivot == -1)
			pivot = i;
		i++;
	}
	pp[j] = 0;
	return (pp);
}

char	**ft_split(char const *s, char c)
{
	char	**pp;
	size_t	pp_size;

	if (!s)
		return (0);
	pp_size = get_size(s, c);
	pp = (char **)malloc(sizeof(char *) * (pp_size + 1));
	if (!pp)
		return (0);
	pp = sub_n_free(s, c, pp, 0);
	return (pp);
}
