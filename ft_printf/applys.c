/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:14:26 by jseol             #+#    #+#             */
/*   Updated: 2021/05/25 18:44:07 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_default(t_format *f, char *dst, char *src, int size)
{
	int	i;
	int	j;
	int	d_len;
	int	s_len;

	i = 0;
	s_len = ft_strlen(src);
	d_len = f->prec != -1 ? f->prec : s_len;
	if (f->spec != 's' && f->spec != 'c' && f-> spec != '%')
		d_len = f->prec > s_len ? f->prec : s_len;
	while (i < size - d_len)
		dst[i++] = ' ';
	if (f->spec != 's' && f->spec != 'c' && f-> spec != '%')
	{
		while (i < size - s_len)
			dst[i++] = '0';
	}
	j = 0;
	while (i < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	ft_putstr(dst);
	free(dst);
	ft_free(src, f);
	return (i);
}

int		apply_minus(t_format *f, char *dst, char *src, int size)
{
	int	i;
	int j;
	int d_len;
	int	s_len;

	i = 0;
	j = 0;
	s_len = ft_strlen(src);
	d_len = f->prec != -1 ? f->prec : s_len;
	if (f->spec != 's' && f->spec != 'c' && f-> spec != '%')
		d_len = f->prec > s_len ? f->prec : s_len;
	if (f->spec != 's' && f->spec != 'c' && f-> spec != '%')
	{
		while (i < (d_len - s_len))
			dst[i++] = '0';
	}
	while (i < size)
		dst[i++] = src[j++];
	while (i < size - d_len)
		dst[i++] = ' ';
	dst[i] = '\0';
	ft_putstr(dst);
	free(dst);
	ft_free(src, f);
	return (i);
}

int		apply_zero(t_format *f, char *dst, char *src, int size)
{
	int	i;
	int	j;
	int	d_len;
	int	s_len;

	i = 0;
	s_len = ft_strlen(src);
	d_len = s_len;
	while (i < size - d_len)
		dst[i++] = '0';
	j = 0;
	while (i < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	ft_putstr(dst);
	free(dst);
	ft_free(src, f);
	return (i);
}
