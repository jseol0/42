/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:12:09 by jseol             #+#    #+#             */
/*   Updated: 2021/05/10 20:06:35 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp;
	const char	*s;
	size_t		i;

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
