/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 08:04:01 by jseol             #+#    #+#             */
/*   Updated: 2021/05/09 07:55:10 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*tmp;
	const char		*s;
	unsigned int	i;

	tmp = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
		{
			tmp[i] = s[i];
			break ;
		}
		tmp[i] = s[i];
		i++;
	}
	if (i == n)
		return (0);
	return (dst + i + 1);
}
