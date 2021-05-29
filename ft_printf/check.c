/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:26:30 by jseol             #+#    #+#             */
/*   Updated: 2021/05/29 13:17:11 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*put_str(t_format *f, char *s)
{
	int		i;
	int		s_len;
	int		size;
	char	*tmp;

	s_len = ft_strlen(s);
	size = f->prec < s_len ? f->prec : s_len;
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[size] = 0;
	i = 0;
	while (i < size)
	{
		tmp[i] = s[i];
		i++;
	}
	return (tmp);
}

int			print_char(t_format *f, char c)
{
	int		cnt;

	cnt = 0;
	if (f->spec == '%' && f->minus == 1)
		f->zero = 0;
	if (f->minus == 1)
		cnt += ft_putchar(c);
	cnt += put_width_char(f->width, 1, f->zero);
	if (f->minus == 0)
		cnt += ft_putchar(c);
	return (cnt);
}

int			print_str(t_format *f, char *s)
{
	int		cnt;
	char	*tmp;

	cnt = 0;
	if (s == NULL)
		s = "(null)";
	if (f->prec < 0 || f->prec > ft_strlen(s))
		f->prec = ft_strlen(s);
	tmp = put_str(f, s);
	cnt = put_width_str(&tmp, f);
	ft_putstr(tmp);
	free(tmp);
	return (cnt);
}

int			print_nbr(t_format *f, unsigned long long num)
{
	int		cnt;
	int		buf_len;
	char	*tmp;
	char	*buf;

	if (f->spec == 'i' || f->spec == 'd')
		tmp = ft_itoa(num, f);
	else if (f->spec == 'u')
		tmp = ft_utoa(num);
	else
		tmp = ft_hextoa(num, f);
	buf_len = ft_strlen(tmp);
	buf = put_prec_nbr(tmp, f, buf_len);
	buf_len += put_minus(f, &buf);
	if (f->spec == 'p')
		buf_len = put_pointer(&buf);
	cnt = put_width_str(&buf, f);
	cnt += put_minus_2(buf_len, f, &buf);
	ft_putstr(buf);
	free(buf);
	return (cnt);
}
