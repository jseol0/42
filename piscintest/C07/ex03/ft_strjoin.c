/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:09:41 by jseol             #+#    #+#             */
/*   Updated: 2021/03/16 14:27:58 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strcat(char *dest, char *src)
{
	while (*src != '\0')
		*dest++ = *src++;
	return (dest);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		strs_size;
	char	*ret;
	char	*tmp;

	strs_size = 0;
	if (size == 0)
	{
		ret = (char *)malloc(sizeof(char));
		return (ret);
	}
	i = 0;
	while (i < size)
		strs_size += ft_strlen(strs[i++]);
	ret = (char *)malloc(strs_size + ((size - 1) * ft_strlen(sep)) + 1);
	tmp = ret;
	tmp = ft_strcat(ret, strs[0]);
	i = 1;
	while (i < size)
	{
		tmp = ft_strcat(tmp, sep);
		tmp = ft_strcat(tmp, strs[i++]);
	}
	*tmp = 0;
	return (ret);
}
