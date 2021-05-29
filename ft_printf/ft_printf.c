/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:08:25 by jseol             #+#    #+#             */
/*   Updated: 2021/05/29 10:19:40 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			check_width_and_prec(va_list *ap,
		const char *format, t_format *f, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (f->prec == -1)
			f->width = (f->width * 10) + (format[i] - 48);
		else
			f->prec = (f->prec * 10) + (format[i] - 48);
	}
	else if (format[i] == '*')
	{
		if (f->prec == -1)
		{
			f->width = va_arg(*ap, int);
			if (f->width < 0)
			{
				f->minus = 1;
				f->width *= -1;
			}
		}
		else
			f->prec = va_arg(*ap, int);
	}
}

void			checkoption(const char *format, int i, t_format *f, va_list *ap)
{
	if (format[i] == '0' && f->width == 0 && f->prec == -1)
		f->zero = 1;
	else if (format[i] == '-')
		f->minus = 1;
	else if (format[i] == '.')
		f->prec = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		check_width_and_prec(ap, format, f, i);
}

int				checkprint(t_format *f, va_list *ap)
{
	int			cnt;
	char		type;

	cnt = 0;
	type = f->spec;
	if (type == 'c')
		cnt = print_char(f, va_arg(*ap, int));
	else if (type == '%')
		cnt = print_char(f, '%');
	else if (type == 's')
		cnt = print_str(f, va_arg(*ap, char *));
	else if (type == 'd' || type == 'i')
		cnt = print_nbr(f, va_arg(*ap, int));
	else if (type == 'x' || type == 'X' || type == 'u')
		cnt = print_nbr(f, va_arg(*ap, unsigned int));
	else if (type == 'p')
		cnt = print_nbr(f, (unsigned long long)va_arg(*ap, void *));
	return (cnt);
}

int				get_format(va_list *ap, const char *format, t_format *f)
{
	int			i;
	int			cnt;

	i = 0;
	cnt = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			cnt += ft_putchar(format[i++]);
		}
		if (format[i] == '%')
		{
			setf(f);
			while (format[++i] != '\0' && !ft_strchr(TYPE, format[i]))
				checkoption(format, i, f, ap);
			f->spec = format[i++];
			if ((f->minus == 1 || f->prec > -1) && f->spec != '%')
				f->zero = 0;
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
	ret = get_format(&ap, (char *)format, &f);
	va_end(ap);
	return (ret);
}
