/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:00:06 by jseol             #+#    #+#             */
/*   Updated: 2021/11/07 18:00:02 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_max_and_min_y(t_mlx *mlx, t_map *map)
{
	int	i;
	int	j;

	map->max = mlx->vectors[0][0].y;
	map->min = mlx->vectors[0][0].y;
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->max < mlx->vectors[j][i].y)
				map->max = mlx->vectors[j][i].y;
			if (map->min > mlx->vectors[j][i].y)
				map->min = mlx->vectors[j][i].y;
			i++;
		}
		j++;
	}
}

static void	get_max_and_min_x(t_mlx *mlx, t_map *map)
{
	int	i;
	int	j;

	map->max = mlx->vectors[0][0].x;
	map->min = mlx->vectors[0][0].x;
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->max < mlx->vectors[j][i].x)
				map->max = mlx->vectors[j][i].x;
			if (map->min > mlx->vectors[j][i].x)
				map->min = mlx->vectors[j][i].x;
			i++;
		}
		j++;
	}
}

static void	adjust_size(t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx->vectors[y][x].x = (x * map->size_x * cos(0.4636 * -1))
				- (y * map->size_x * sin(1.1071 * -1));
			mlx->vectors[y][x].y = (x * map->size_y * sin(0.4636 * -1))
				+ (y * map->size_y * cos(1.1071 * -1))
				- map->z[y][x] * map->size_y;
			x++;
		}
		y++;
	}
}

static void	adjust_default(t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx->vectors[y][x].x += map->default_x;
			mlx->vectors[y][x].y += map->default_y;
			x++;
		}
		y++;
	}
}

void	size_control(t_mlx *mlx, t_map *map)
{
	int	dx;
	int	dy;

	get_max_and_min_x(mlx, map);
	dx = map->max - map->min;
	get_max_and_min_y(mlx, map);
	dy = map->max - map->min;
	map->size_x = (WIN_WIDTH * 0.8) / dx;
	map->size_y = (WIN_HEIGHT * 0.8) / dy;
	adjust_size(mlx, map);
	get_max_and_min_x(mlx, map);
	dx = map->max - map->min;
	map->default_x = (WIN_WIDTH / 2) - (dx / 2);
	get_max_and_min_y(mlx, map);
	dy = map->max - map->min;
	if (map->min < 0)
		dy = map->min + map->max;
	map->default_y = (WIN_HEIGHT / 2) - (dy / 2);
	adjust_default(mlx, map);
}
