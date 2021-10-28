/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:59:40 by jseol             #+#    #+#             */
/*   Updated: 2021/10/28 18:42:54 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_projection(t_mlx *mlx, t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	mlx->vectors = (t_vector **)ft_malloc(sizeof(t_vector *), map->height);
	while (i < map->height)
		mlx->vectors[i++] = (t_vector *)ft_malloc(sizeof(t_vector), map->width);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx->vectors[y][x].x = ((x * 20) * cos(0.5236)) - ((y * 20) * sin(0.5236));		// 사이즈 곱해져 있음
			mlx->vectors[y][x].y = ((x * 20) * sin(0.5236)) + ((y * 20) * cos(0.5236)) - (map->z[y][x] * 20);
			x++;
		}
		y++;
	}
}

/*

사이즈 늘리기

*/
