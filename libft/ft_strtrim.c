/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:21:59 by jseol             #+#    #+#             */
/*   Updated: 2021/05/09 16:17:51 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_set(char c, char const *set)
{
	int i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *ret;
	int start;
	int end;
	int i;

	i = 0;
	while (is_set((s1[i]), set))
		i++;
	start = i;
	i = 0;
	while (is_set(s1[ft_strlen(s1) - i - 1], set));
		i++;
	end = i;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) - start - end + 1));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1 + start, ft_strlen(s1) - start - end);	// ft_substr
	return (ret);
}
