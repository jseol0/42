/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 09:24:09 by jseol             #+#    #+#             */
/*   Updated: 2021/05/10 19:07:30 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*tmp;
	const char		*s;
	unsigned int	i;

	tmp = dst;
	s = src;
	i = 0;
	if (dst <= src)
	{
		while (i < len)
		{
			tmp[i] = s[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			tmp[len - i - 1] = s[len - i - 1];
			i++;
		}
	}
	return (dst);
}
