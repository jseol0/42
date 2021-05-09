/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:20:48 by jseol             #+#    #+#             */
/*   Updated: 2021/03/11 14:35:06 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

int			ft_base_check(char *base)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = base;
	while (tmp[i] != '\0')
	{
		if (base[0] == '\0' || ft_strlen(base) == 1)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (tmp[i] == tmp[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		ft_dectobase(int i, int *nbr_index, char *base)
{
	while (--i >= 0)
	{
		if (nbr_index[i] < 0)
			nbr_index[i] = -nbr_index[i];
		write(1, &base[nbr_index[i]], 1);
	}
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		base_size;
	int		nbr_index[42];

	i = 0;
	base_size = ft_strlen(base);
	if (ft_base_check(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
		}
		if (nbr == 0)
		{
			nbr_index[i] = 0;
			i++;
		}
		while (nbr != 0)
		{
			nbr_index[i] = nbr % base_size;
			nbr /= base_size;
			i++;
		}
		ft_dectobase(i, nbr_index, base);
	}
}
int	main()
{
	ft_putnbr_base(16, "0123456789abcdef");
}
