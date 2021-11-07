/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:59:40 by jseol             #+#    #+#             */
/*   Updated: 2021/11/07 17:31:46 by jseol            ###   ########.fr       */
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
			mlx->vectors[y][x].x = (x * cos(0.4636 * -1))
				- (y * sin(1.1071 * -1));
			mlx->vectors[y][x].y = (x * sin(0.4636 * -1))
				+ (y * cos(1.1071 * -1)) - map->z[y][x];
			x++;
		}
		y++;
	}
}
