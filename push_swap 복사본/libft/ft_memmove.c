/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 09:24:09 by jseol             #+#    #+#             */
/*   Updated: 2021/05/11 13:22:05 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*tmp;
	const char		*s;
	size_t			i;

	tmp = dst;
	s = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (dst <= src)
		while (i < len)
		{
			tmp[i] = s[i];
			i++;
		}
	else
		while (i < len)
		{
			tmp[len - i - 1] = s[len - i - 1];
			i++;
		}
	return (dst);
}
