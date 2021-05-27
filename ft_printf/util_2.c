/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:13:43 by jseol             #+#    #+#             */
/*   Updated: 2021/05/27 23:47:50 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void			*ft_memcpy(void *dst, const void *src, int n)
{
	char		*tmp;
	const char	*s;
	int			i;

	if (!dst && !src)
		return (0);
	tmp = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		tmp[i] = s[i];
		i++;
	}
	return (dst);
}

char		*ft_strjoin(char *s1, char *s2, int freeptr)
{
	char	*ret;
	int		s1_len;
	int		s2_len;
	int		len;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, s1_len);
	if (freeptr == 1 || freeptr == 0)
		free(s1);
	ft_memcpy(ret + s1_len, s2, s2_len);
	if (freeptr == 2 || freeptr == 0)
		free(s2);
	ret[len] = '\0';
	return (ret);
}

char		*ft_strdup(char *s1)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
