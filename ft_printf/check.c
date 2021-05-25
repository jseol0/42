/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:26:30 by jseol             #+#    #+#             */
/*   Updated: 2021/05/25 18:44:14 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int			applyformat(t_format *f, char *dst, char *src, int size)
{
	int		cnt;

	cnt = 0;
	if (f->spec == 'c' || f->spec == '%')
		f->prec = -1;
	if (f->prec >= 0 || f->minus == 1 || f->spec == 'c' || f->spec == 's')
		f->zero = 0;
	if (f->minus == 0 && f->zero == 0)
		cnt = apply_default(f, dst, src, size);
	if (f->minus == 1)
		cnt = apply_minus(f, dst, src, size);
	if (f->zero == 1)
		cnt = apply_zero(f, dst, src, size);
	return (cnt);
}

int			get_size(t_format *f, char *s)
{
	int		s_len;
	int		size;
	char	type;

	type = f->spec;
	s_len = ft_strlen(s);
	size = 0;
	if (type == 'd' || type == 'i' || type == 'u'
		|| type == 'x' || type == 'X' || type == 'p')
	{
		size = f->width > f->prec ? f->width : f->prec;
		size = size > s_len ? size : s_len;
	}
	else if (type == 's')
	{
		size = f->prec != -1 ? f->prec : s_len;
		size = f->width != 0 ? f->width : size;
	}
	else if (type == 'c' || type == '%')
		size = f->width != 0 ? f->width : 1;
	return (size);
}

int			print_char(t_format *f, char c)
{
	int		cnt;
	char	arr[2];
	char	*tmp;

	cnt = 0;
	arr[0] = c;
	if (f->spec == '%')
		arr[0] = '%';
	arr[1] = '\0';
	tmp = arr;
	return (cnt = print_str(f, tmp));
}

int			print_str(t_format *f, char *s)
{
	int		cnt;
	char	*tmp;
	int		size;

	cnt = 0;
	size = get_size(f, s);
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (tmp == 0)
		return (0);
	return (cnt = applyformat(f, tmp, s, size));
}

int			print_nbr(t_format *f, unsigned long long num)
{
	int		cnt;
	char	type;
	char	*tmp;
	//캐스팅 고려하기
	cnt = 0;
	type = f->spec;
	if (type == 'i' || type == 'd')
		tmp = ft_itoa(num);
	else if (type == 'u')
		tmp = ft_utoa(num);
	else
		tmp = ft_hextoa(num, f);
	return (cnt = print_str(f, tmp));
}
