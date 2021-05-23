/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:26:30 by jseol             #+#    #+#             */
/*   Updated: 2021/05/23 19:48:42 by jseol            ###   ########.fr       */
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
	size = 0;
	if (type == 'd' || type == 'i' || type == 'u'
		|| type == 'x' || type == 'X' || type == 'p')
	{
		size = f->width > f->prec ? f->width : f->prec;
		size = size > s_len ? size : s_len;
	}
	else if (type == 's')
		size = f->prec != -1 ? f->prec : s_len;
	else if (type == 'c' || type == '%')
		size = f->width != 0 ? f->width : 1;
	return (size);
}

int			print_str(t_format *f, char *s)
{
	int		cnt;
	char	*tmp;
	int		size;

	cnt = 0;
	size = get_size(f, s);
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	return (cnt = applyformat(f, tmp));
}

int			print_nbr(t_format *f, unsigned long long num)
{
	int		cnt;
	char	type;
	char	*tmp;

	type = f->spec;
	cnt = 0;
	// tmp = atoi or atoibase
	if (type == 'i' || type == 'd')
		tmp = ft_itoa(num, f);
	else if (type == 'u')
		tmp = ft_utoa(num, f);
	else if (type == 'x' || type == 'X' || type == 'p')
		tmp = ft_hextoa(num, f);

	return (cnt = print_str(f, tmp));
}
