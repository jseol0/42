/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:14:26 by jseol             #+#    #+#             */
/*   Updated: 2021/05/26 16:46:15 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_default(t_format *f, char *dst, char *src, int size)
{
	int cnt;

	if ((f->spec == 'd' || f->spec == 'i') && src[0] == '-')
		cnt = input_default_neg(f, dst, src, size);
	else
		cnt = input_default_plus(f, dst, src, size);
	ft_putstr(dst);
	free(dst);
	ft_free(src, f);
	return (cnt);
}

int		apply_minus(t_format *f, char *dst, char *src, int size)
{
	int cnt;

	if ((f->spec == 'd' || f->spec == 'i') && src[0] == '-')
		cnt = input_minus_neg(f, dst, src, size);
	else
		cnt = input_minus_plus(f, dst, src, size);
	ft_putstr(dst);
	free(dst);
	ft_free(src, f);
	return (cnt);
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
