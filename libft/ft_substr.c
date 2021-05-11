/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 09:59:31 by jseol             #+#    #+#             */
/*   Updated: 2021/05/11 16:05:35 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return(ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len && i + start < s_len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	substr_length;
	char	*ret;
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < start && s[i] != '\0')
		i++;
	substr_length = 0;
	while (s[i] != '\0' && i - start < len)
	{
		substr_length++;
		i++;
	}
	ret = (char *)malloc((substr_length + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s + start, substr_length);
	ret[substr_length] = '\0';
	return (ret);
}
