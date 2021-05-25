/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:13:43 by jseol             #+#    #+#             */
/*   Updated: 2021/05/25 18:44:13 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncpy(char *s1, char *s2, int n)
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

void	ft_free(char *tmp, t_format *f)
{
	if (tmp && ( f->spec != 's' && f->spec != 'c' &&
		f->spec != '%'))
		free(tmp);
}
