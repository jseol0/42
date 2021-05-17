/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:35:18 by jseol             #+#    #+#             */
/*   Updated: 2021/05/17 16:02:05 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	s = (char *)src;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(s);
	i = 0;
	while (src[i] != '\0' && dst_len + 1 + i < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (dstsize < dst_len)
		return (dstsize + src_len);
	return (dst_len + src_len);
}

char		*ft_strdup(char *s)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s1, s1_len + 1);
	free(s1);
	ft_strlcat(ret + (s1_len), s2, s2_len + 1);
	return (ret);
}
