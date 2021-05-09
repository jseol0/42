/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:47:34 by jseol             #+#    #+#             */
/*   Updated: 2021/03/16 10:22:43 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int					*ft_range(int min, int max)
{
	unsigned int	i;
	int				*ret;
	unsigned int	size;

	if (min >= max)
		return (NULL);
	size = max - min;
	ret = (int *)malloc(sizeof(int) * size);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (size)
	{
		ret[i] = min + i;
		i++;
		size--;
	}
	return (ret);
}
