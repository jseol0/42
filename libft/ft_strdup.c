/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 09:34:16 by jseol             #+#    #+#             */
/*   Updated: 2021/05/09 09:44:13 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*strdup(const char *s1)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
