/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:13:10 by elim              #+#    #+#             */
/*   Updated: 2021/10/28 15:43:48 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*sub;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		size = ft_strlen(s) - start;
	else
		size = len;
	sub = (char *)malloc(sizeof(char) * (size + 1));
	if (!sub)
		return (0);
	ft_memcpy(sub, s + start, size);
	sub[size] = 0;
	return (sub);
}
