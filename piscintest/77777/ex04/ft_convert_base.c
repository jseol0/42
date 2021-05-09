/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:51:25 by jseol             #+#    #+#             */
/*   Updated: 2021/03/16 10:26:12 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				find_index(char c, char *base, int base_size);
int				ft_char_check(char str);
int				ft_base_check(char *base, int base_size);
int				ft_strlen(char *str);

char			*foo(char *buf)
{
	int			i;
	char		*ret;

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

char			*ft_itoa(int nbr, char *base)
{
	char		buf[42];
	int			i;
	int			sign;
	long long	ll_nbr;

	ll_nbr = nbr;
	sign = 1;
	if (ll_nbr < 0)
	{
		sign *= -1;
		ll_nbr *= -1;
	}
	i = 0;
	while (1)
	{
		buf[i++] = base[(ll_nbr % ft_strlen(base))];
		ll_nbr = ll_nbr / ft_strlen(base);
		if (ll_nbr == 0)
			break ;
	}
	if (sign == -1)
		buf[i++] = '-';
	buf[i] = '\0';
	return (foo(buf));
}

int				ft_atoi_base(char *str, char *base_from)
{
	int			i;
	int			sign;
	int			ret;

	sign = 1;
	ret = 0;
	i = 0;
	while (ft_char_check(str[i]))
	{
		sign *= ft_char_check(str[i]);
		i++;
	}
	while (str[i] != '\0')
	{
		if (find_index(str[i], base_from, ft_strlen(base_from)) != -1)
		{
			ret *= ft_strlen(base_from);
			ret += find_index(str[i], base_from, ft_strlen(base_from))
				* sign;
			i++;
		}
		else
			break ;
	}
	return (ret);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			num;
	char		*ret;

	if (ft_base_check(base_from, ft_strlen(base_from))
			&& ft_base_check(base_to, ft_strlen(base_to)))
		num = ft_atoi_base(nbr, base_from);
	else
		return (NULL);
	ret = ft_itoa(num, base_to);
	return (ret);
}
