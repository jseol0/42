/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:08:25 by jseol             #+#    #+#             */
/*   Updated: 2021/05/19 17:00:30 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setf(t_format *f)
{
	f->zero = 0;
	f->neg = 0;
	f->widht = 0;
	f-> prec = -1;
}

void	checkoption(char *format, int i, t_format *f, va_list ap)
{
	// 정밀도랑 너비 체크하기
	if (format[i] == '-')
		f->neg = 1;
	else if (format[i] == '0')
		f->zero = 1;
	else if (format[i] == '.')
		f->prec = 0;
	else if (format[i] == '*')
		f->widht = va_arg(ap, int);
	else if (format[i] >= '0' && format[i] <= '9')
		f->widht = (f->widht * 10) + (format[i] - '0');

}

int		get_format(va_list ap, char *format, t_format *f)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	setf(f);
	while (format[i])
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			i++;
			cnt++;
		}
		if (format[i] == '%')
		{
			while (!ft_strchr(TYPE, format[i]))
			{
				checkoption(format, i, f, ap);
				i++;
			}
			f->spec = format[i];
			cnt += checkprint(format, i, f, ap);
		}
	}
	return (cnt);
}

int				ft_printf(const char *format, ...)
{
	va_list 	ap;
	int			ret;
	t_format	f;

	va_start(ap, format);
	ret = get_format(ap, format, &f);
	va_end(ap);
	return (ret);
}
