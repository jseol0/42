/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:26:30 by jseol             #+#    #+#             */
/*   Updated: 2021/05/26 23:27:03 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_size(t_format *f, char *s)
{
	int		s_len;
	int		size;
	char	type;

	type = f->spec;
	s_len = ft_strlen(s);
	size = f->prec < s_len ? f->prec : s_len;
	return (size);
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
	return (cnt);
}

int			print_str(t_format *f, char *s)
{
	int		i;
	int		cnt;
	char	*tmp;
	int		size;

	cnt = 0;
	if (s == NULL)
		return (ERROR);
	if (f->prec == -1 || f->prec > ft_strlen(s))
		f->prec = ft_strlen(s);
	size = get_size(f, s);
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (ERROR);
	i = 0;
	while (i++ < size)
		tmp[i] = s[i];
	tmp[i] = '\0';
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

	if ((f->spec == 'd' || f->spec == 'i') && (int)num < 0)
	{
		f->num_sign = -1;
		num *= -1;
	}
	if (f->spec == 'i' || f->spec == 'd')
		tmp = ft_itoa(num);
	else if (f->spec == 'u')
		tmp = ft_utoa(num);
	else
		tmp = ft_hextoa(num, f);
	buf_len = ft_strlen(tmp);
	buf = put_prec_nbr(tmp, f, buf_len);	//free(tmp);
	buf_len += put_minus(f, &buf);
	if (f->spec == 'p')
		buf_len = put_pointer(&buf);
	cnt = put_width_str(&buf, f);
	cnt += put_minus_2(buf_len, f, &buf);
	ft_putstr(buf);
	free(buf);
	return (cnt);
}
