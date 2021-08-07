/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:10:08 by jseol             #+#    #+#             */
/*   Updated: 2021/07/31 16:37:49 by jseol            ###   ########.fr       */
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
			depth = map->code[cur.height][cur.width];
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
