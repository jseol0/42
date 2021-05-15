/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:35:18 by jseol             #+#    #+#             */
/*   Updated: 2021/05/15 17:12:08 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strncat(char *s1, char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (j < len)
	{
		s1[i] = s2[i + j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
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

	if (s1 == NULL)
	{
		ret = ft_strdup(s2);
		return (ret);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ret == NULL)
		return (NULL);
	ft_strncat(ret, s1, s1_len);
	free(s1);
	ft_strncat(ret, s2, s2_len);
	return (ret);
}
