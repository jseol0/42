/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 12:56:13 by jseol             #+#    #+#             */
/*   Updated: 2021/03/14 02:43:04 by jseol            ###   ########.fr       */
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

char		*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*ret;

	size = ft_strlen(src);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
