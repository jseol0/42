/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:13:43 by jseol             #+#    #+#             */
/*   Updated: 2021/05/26 11:51:07 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strncpy(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (i < n && s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[n] = '\0';
	return (s1);
}

void		ft_free(char *tmp, t_format *f)
{
	if (tmp && (f->spec != 's' && f->spec != 'c' &&
		f->spec != '%'))
		free(tmp);
}

char		*ft_strdup(char *s1)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
