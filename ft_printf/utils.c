/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:31:09 by jseol             #+#    #+#             */
/*   Updated: 2021/05/20 16:22:48 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int		ft_putstr(char *s)
{
	int	i;

	if (s == 0)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

size_t get_size(t_format *f, char *s);

int			print_str(t_format *f, char *s)
{
	int		cnt;
	char	*tmp;
	size_t	size;

	cnt = 0;
	size = get_size(f, s);
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	return (cnt = applyformat(f, tmp));
}

int		print_nbr(t_format *f, unsigned long long num)
{
	int cnt;
	char *tmp;

	cnt = 0;
	// tmp = atoi or atoibase

	return (cnt = print_str(f, tmp));
}
