/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:59:40 by jseol             #+#    #+#             */
/*   Updated: 2021/10/26 15:46:32 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_projection(t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	map->vectors = (t_vector **)ft_malloc(sizeof(t_vector *), map->height);
	while (i < map->height)
		map->vectors[i++] = (t_vector *)ft_malloc(sizeof(t_vector), map->width);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->vectors[y][x].x = (x * cos(0.5236)) - (y * sin(0.5236));
			map->vectors[y][x].y = (x * sin(0.5236)) + (y * cos(0.5236)) - map->z[y][x];
			x++;
		}
		y++;
	}
}
