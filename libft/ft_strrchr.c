/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:28:15 by jseol             #+#    #+#             */
/*   Updated: 2021/05/09 16:17:50 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*strrchr(const char *s, int c)
{
	int		i;
	int		slen;
	char	*tmp_s;
	char	tmp_c;

	tmp_s = (char *)s;
	tmp_c = c;
	slen = ft_strlen(s);
	i = 0;
	while (tmp_s[slen - 1 - i] != tmp_c)
	{
		if (i == slen - 1)
			return (NULL);
		i++;
	}
	return (&tmp_s[slen - 1 - i]);
}
