/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:43:06 by jseol             #+#    #+#             */
/*   Updated: 2021/07/31 17:14:55 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_mlx *mlx)
{
	int		x;
	int		y;
	t_map	*map;
	t_image	*img;

	map = mlx->map;
	img = mlx->image;
	x = 0;
	while (x < (map->width * 10) + 1)
	{
		y = 0;
		while (y < (map->height * 10) + 1)
		{
			if (x == 0 || y == 0 || x % 10 == 0 || y % 10 == 0)
				my_mlx_pixel_put(img, x, y, WHITE/*get_color(mlx->map, x, y)*/);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
