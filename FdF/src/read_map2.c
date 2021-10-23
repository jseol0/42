/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:10:08 by jseol             #+#    #+#             */
/*   Updated: 2021/10/23 17:39:28 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_depth(t_map *map)
{
	t_map	cur;
	int	min;
	int	max;
	int	depth;

	min = 2147483647;
	max = -2147483648;
	cur.height = 0;
	while (cur.height < map->height)
	{
		cur.width = 0;
		while (cur.width < map->width)
		{
			depth = map->z[cur.height][cur.width];
			if (depth < min)
				min = depth;
			if (depth > max)
				max = depth;
			cur.width++;
		}
		cur.height++;
	}
	map->min_depth = min;
	map->max_depth = max;
}

int		divide_z(char *split, int col_val)
{
	char	*z;
	int		ret;

	z = (char *)ft_malloc(sizeof(char), 1);
	z = ft_strncpy(z, split, col_val);
	ret = ft_atoi(z);
	free(z);

	return (ret);
}

int		divide_col(char *split, int col_val)
{
	char	*col;
	int		ret;

	col = (char *)ft_malloc(sizeof(char), 1);
	col = ft_strcpy(col, split + col_val + 3);
	ret = ft_atoi_base(col, "0123456789ABCDEF");
	free(col);

	return (ret);
}
