/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:33:32 by elim              #+#    #+#             */
/*   Updated: 2021/10/23 16:41:08 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	ret;
	size_t	len;

	ret = ft_strlen(src);
	if (size)
	{
		if (ret >= size)
			len = size - 1;
		else
			len = ret;
		ft_memcpy(dst, src, len);
		dst[len] = 0;
	}
	return (ret);
}
