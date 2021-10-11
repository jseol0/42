/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:10:08 by jseol             #+#    #+#             */
/*   Updated: 2021/10/07 22:14:32 by jseol            ###   ########.fr       */
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

void	color(t_map *map, int y, int x)
{
	int	color;
	int	cur;
	int	max;
	int	min;

	color = WHITE;
	cur = map->z[y][x];
	max = map->max_depth;
	min = map->min_depth;
	if (max >= cur  && cur > (max / 3) * 2)
		color = RED;
	else if ((max / 3) * 2 >= cur && cur > max / 3)
		color = ORANGE;
	else if (max / 3 >= cur && cur > 0)
		color = YELLOW;
	else if (0 > cur  && cur >= min / 3)
		color = GREEN;
	else if (min / 3 > cur && cur >= (min / 3) * 2)
		color = BLUE;
	else if ((min / 3) * 2 > cur && cur >= min)
		color = PURPLE;

	return (color);
}

void	get_color(t_map *map)
{
	int	x;
	int	y;

	map->color = (int **)ft_malloc(sizeof(int *), (map->height));
	y = 0;
	while (y < map->height)
	{
		map->color[y] = (int *)ft_malloc(sizeof(int), (map->width))
		x = 0;
		while (x < map->width)
		{
			map->color[y][x] = (map, y, x);
			x++;
		}
		y++;
	}
}
