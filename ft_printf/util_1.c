/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:31:09 by jseol             #+#    #+#             */
/*   Updated: 2021/05/23 19:48:44 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *s)
{
	int i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int		ft_putstr(char *s)
{
	int	i;

	if (s == 0)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

void			setf(t_format *f)
{
	f->zero = 0;
	f->neg = 0;
	f->width = 0;
	f->prec = -1;
}

