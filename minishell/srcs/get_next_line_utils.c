/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:03:42 by elim              #+#    #+#             */
/*   Updated: 2022/01/23 20:21:56 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(char const *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (!dst && !src)
		return (0);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*tmp_dst++ = *tmp_src++;
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * size + 1);
	if (!dup)
		return (0);
	ft_memcpy(dup, src, size + 1);
	return (dup);
}

char	*mod_substr(char *src, int i)
{
	size_t	size;
	char	*sub;

	if (!src)
		return (0);
	size = i;
	sub = (char *)malloc(sizeof(char) * (size + 1));
	if (!sub)
		return (0);
	ft_memcpy(sub, src, size);
	sub[size] = 0;
	return (sub);
}

char	*mod_strjoin(char *s1, char *s2)
{
	size_t	size;
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = s1_len + s2_len;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	ft_memcpy(str, s1, s1_len);
	free(s1);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[size] = 0;
	return (str);
}
