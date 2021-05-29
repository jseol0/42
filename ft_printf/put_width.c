/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:44:16 by jseol             #+#    #+#             */
/*   Updated: 2021/05/29 10:17:50 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_width_char(int width, int len, int zero)
{
	int		cnt;

	cnt = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		cnt++;
	}
	return (cnt);
}

int			put_width_str(char **buf, t_format *f)
{
	char	*width;
	int		i;

	if (f->width <= ft_strlen(*buf))
		return (ft_strlen(*buf));
	width = (char *)malloc(sizeof(char) * (f->width - ft_strlen(*buf) + 1));
	i = 0;
	while (i < f->width - ft_strlen(*buf))
	{
		width[i] = (f->zero == 1) ? '0' : ' ';
		i++;
	}
	width[i] = '\0';
	if (f->minus == 0)
		*buf = ft_strjoin(width, *buf, 0);
	else
		*buf = ft_strjoin(*buf, width, 0);
	return (f->width);
}
