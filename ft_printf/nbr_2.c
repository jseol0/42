/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:49:44 by jseol             #+#    #+#             */
/*   Updated: 2021/05/27 23:47:50 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_minus_2(int buf_len, t_format *f, char **buf)
{
	int		addlen;

	addlen = 0;
	if (f->num_sign == -1 && f->zero == 1)
	{
		if (buf_len >= f->width)
		{
			*buf = ft_strjoin("-", *buf, 2);
			addlen = 1;
		}
		else if (buf_len < f->width)
			*buf[0] = '-';
	}
	return (addlen);
}

int			put_pointer(char **buf)
{
	*buf = ft_strjoin("0x", *buf, 2);
	return (ft_strlen(*buf));
}

int			put_minus(t_format *f, char **buf)
{
	int addlen;

	addlen = 0;
	if ((f->spec == 'd' || f->spec == 'i') &&
		f->zero == 0 && f->num_sign == -1)
	{
		*buf = ft_strjoin("-", *buf, 2);
		addlen = 1;
	}
	return (addlen);
}

char		*put_prec_nbr(char *tmp, t_format *f, int buf_len)
{
	int		i;
	int		j;
	int		ret;
	char	*buf;

	if (tmp[0] == '0' && f->prec == 0)
	{
		buf = ft_strdup("");
		return (buf);
	}
	ret = (f->prec > buf_len) ? f->prec : buf_len;
	if (!(buf = (char *)malloc(sizeof(char) * ret + 1)))
		return (0);
	i = 0;
	while (buf_len + i < ret)
		buf[i++] = '0';
	j = 0;
	while (tmp[j] != '\0')
		buf[i++] = tmp[j++];
	buf[i] = '\0';
	free(tmp);
	return (buf);
}
