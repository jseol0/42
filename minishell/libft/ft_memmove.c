/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:37:25 by elim              #+#    #+#             */
/*   Updated: 2020/10/14 21:01:42 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (!dst && !src)
		return (0);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (dst <= src)
	{
		while (n--)
			*tmp_dst++ = *tmp_src++;
	}
	else
	{
		tmp_dst += n - 1;
		tmp_src += n - 1;
		while (n--)
			*tmp_dst-- = *tmp_src--;
	}
	return (dst);
}
