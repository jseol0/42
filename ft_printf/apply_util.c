/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:35:03 by jseol             #+#    #+#             */
/*   Updated: 2021/05/26 16:46:13 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int input_default_neg(t_format *f, char *dst, char *src, int size)
{
	int	i;
	int	j;
	int	d_len;
	int	s_len;

	i = 0;
	s_len = ft_strlen(src);
	d_len = f->prec != -1 ? f->prec : s_len;
	if (f->spec != 's' && f->spec != 'c' && f->spec != '%')
		d_len = f->prec > s_len ? f->prec : s_len;
	while (i < size - (d_len + 1))
		dst[i++] = ' ';
	if (f->spec != 's' && f->spec != 'c' && f->spec != '%')
	{
		dst[i++] = '-';
		while (i < size - s_len)
			dst[i++] = '0';
	}
	j = 1;
	while (i < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (i);
}

int input_default_plus(t_format *f, char *dst, char *src, int size)
{
	int	i;
	int	j;
	int	d_len;
	int	s_len;

	i = 0;
	s_len = ft_strlen(src);
	d_len = f->prec != -1 ? f->prec : s_len;
	if (f->spec != 's' && f->spec != 'c' && f->spec != '%')
		d_len = f->prec > s_len ? f->prec : s_len;
	while (i < size - (d_len))
		dst[i++] = ' ';
	if (f->spec != 's' && f->spec != 'c' && f->spec != '%')
	{
		while (i < size - s_len)
			dst[i++] = '0';
	}
	j = 0;
	while (i < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (i);
}

int input_minus_neg(t_format *f, char *dst, char *src, int size)
{
	int	i;
	int j;
	int d_len;
	int	s_len;

	i = 0;
	j = 1;
	s_len = ft_strlen(src);
	d_len = f->prec != -1 ? f->prec : s_len;
	if (f->spec != 's' && f->spec != 'c' && f->spec != '%')
		d_len = f->prec > s_len ? f->prec : s_len;
	if (f->spec != 's' && f->spec != 'c' && f->spec != '%')
	{
		dst[i++] = '-';
		while (i < (d_len - s_len))
			dst[i++] = '0';
	}
	while (i < size - (size - d_len))
		dst[i++] = src[j++];
	while (i < size)
		dst[i++] = ' ';
	dst[i] = '\0';
	return (i);
}

int input_minus_plus(t_format *f, char *dst, char *src, int size)
{
	int	i;
	int j;
	int d_len;
	int	s_len;

	i = 0;
	j = 0;
	s_len = ft_strlen(src);
	d_len = f->prec != -1 ? f->prec : s_len;
	if (f->spec != 's' && f->spec != 'c' && f->spec != '%')
		d_len = f->prec > s_len ? f->prec : s_len;
	if (f->spec != 's' && f->spec != 'c' && f->spec != '%')
	{
		while (i < (d_len - s_len))
			dst[i++] = '0';
	}
	while (i < d_len)
		dst[i++] = src[j++];
	while (i < size)
		dst[i++] = ' ';
	dst[i] = '\0';
	return (i);
}
