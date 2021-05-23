/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:08:25 by jseol             #+#    #+#             */
/*   Updated: 2021/05/23 19:48:47 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			checkoption(char *format, int i, t_format *f, va_list ap)
{
	if (format[i] == '-')
		f->neg = 1;
	else if (format[i] == '0')
		f->zero = 1;
	else if (format[i] == '.')
		f->prec = 0;
	else if (format[i] == '*' && f->prec == -1)
		f->width = va_arg(ap, int);
	else if (format[i] == '*' && f->prec == 0)
		f->prec = va_arg(ap, int);
	else if ((format[i] >= '0' && format[i] <= '9') && f->prec == -1)
		f->width = (f->width * 10) + (format[i] - '0');
	else if ((format[i] >= '0' && format[i] <= '9') && f->prec == 0)
		f->prec = (f->prec * 10) + (format[i] - '0');
	if (f->zero == 1 && f->prec >= 0)
		f->zero == 0;
}

int				checkprint(t_format *f, va_list ap)
{
	int			cnt;
	char		type;

	cnt = 0;
	type = f->spec;
	if (type == 'c')
		cnt = print_char(f, va_arg(ap, int));
	else if (type == '%')
		cnt = print_char(f, '%');
	else if (type == 's')
		cnt = print_str(f, va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
		cnt = print_nbr(f, va_arg(ap, int));
	else if (type == 'x' || type == 'X' || type == 'u')
		cnt = print_nbr(f, va_arg(ap, unsigned int));
	else if (type == 'p')
		cnt = print_nbr(f, va_arg(ap, unsigned long long));
	return (cnt);
}

int				get_format(va_list ap, char *format, t_format *f)
{
	int			i;
	int			cnt;

	i = 0;
	cnt = 0;
	setf(f);
	while (format[i])
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			i++;
			cnt += ft_putchar(format[i]);
		}
		if (format[i] == '%')
		{
			while (!ft_strchr(TYPE, format[i]))
			{
				checkoption(format, i, f, ap);
				i++;
			}
			f->spec = format[i];
			cnt += checkprint(f, ap);
		}
	}
	return (cnt);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	t_format	f;

	va_start(ap, format);
	ret = get_format(ap, format, &f);
	va_end(ap);
	return (ret);
}
