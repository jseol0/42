/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:34:44 by elim              #+#    #+#             */
/*   Updated: 2021/10/28 15:31:06 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	int		i;
	char	tmp[11];

	if (fd < 0)
		return ;
	if (!n)
	{
		write(fd, "0", 1);
		return ;
	}
	sign = 1;
	if (n < 0)
		sign = -1;
	i = 0;
	while (n)
	{
		tmp[i] = n % 10 * sign + 48;
		n /= 10;
		i++;
	}
	if (sign == -1)
		write(fd, "-", 1);
	while (--i >= 0)
		write(fd, &tmp[i], 1);
}
