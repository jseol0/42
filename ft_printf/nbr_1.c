/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:34:34 by jseol             #+#    #+#             */
/*   Updated: 2021/05/27 23:47:51 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*putret(char *buf)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (buf[i] != '\0')
	{
		ret[i] = buf[ft_strlen(buf) - i - 1];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char		*ft_itoa(int n, t_format *f)
{
	char	buf[42];
	int		i;
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign *= -1;
		f->num_sign = -1;
	}
	i = 0;
	while (1)
	{
		buf[i] = sign * (n % 10) + '0';
		n /= 10;
		i++;
		if (n == 0)
			break ;
	}
	buf[i] = '\0';
	return (putret(buf));
}

char		*ft_utoa(unsigned int n)
{
	char	buf[42];
	int		i;

	i = 0;
	while (1)
	{
		buf[i] = (n % 10) + '0';
		n /= 10;
		i++;
		if (n == 0)
			break ;
	}
	buf[i] = '\0';
	return (putret(buf));
}

char		*ft_hextoa(unsigned long long n, t_format *f)
{
	char	buf[42];
	int		i;

	i = 0;
	while (1)
	{
		if (f->spec == 'X')
			buf[i] = UPBASE[(n % 16)];
		else
			buf[i] = BASE[(n % 16)];
		n /= 16;
		i++;
		if (n == 0)
			break ;
	}
	buf[i] = '\0';
	return (putret(buf));
}
