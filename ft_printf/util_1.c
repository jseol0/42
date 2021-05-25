/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:31:09 by jseol             #+#    #+#             */
/*   Updated: 2021/05/25 18:44:08 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(char *s)
{
	int i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int			ft_putchar(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

void			ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

void		setf(t_format *f)
{
	f->zero = 0;
	f->minus = 0;
	f->width = 0;
	f->prec = -1;
}

int			ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp_s;
	char	tmp_c;

	tmp_s = (char *)s;
	tmp_c = c;
	i = 0;
	while (tmp_s[i] != tmp_c)
	{
		if (tmp_s[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}
