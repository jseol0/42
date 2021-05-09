/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 00:04:26 by jseol             #+#    #+#             */
/*   Updated: 2021/03/16 10:41:39 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int					i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void					ft_strcpy(char *dest, char *src)
{
	int					i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str			*ret;
	int					i;

	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = av[i];
		ret[i].copy = (char *)malloc(sizeof(char) * (ret[i].size + 1));
		if (ret == NULL)
			return (NULL);
		ft_strcpy(ret[i].copy, av[i]);
		i++;
	}
	ret[i].str = NULL;
	return (ret);
}
