/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:43:06 by jseol             #+#    #+#             */
/*   Updated: 2021/10/27 17:04:06 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->ptr + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void	dda(t_mlx *mlx, int x, int y)
{
	int	i;
	float	step;
	float	xinc;
	float	yinc;
	t_vector	**v;

	v = mlx->vectors;
	if (fabs(v[y][x + 1].x) - fabs(v[y][x].x) > fabs(v[y][x + 1].y) - fabs(v[y][x].y))
		step = fabs(v[y][x + 1].x) - fabs(v[y][x].x);
	else
		step = fabs(v[y][x + 1].y) - fabs(v[y][x].y);
	xinc = (fabs(v[y][x + 1].x) - fabs(v[y][x].x)) / step;
	yinc = (fabs(v[y + 1][x].y) - fabs(v[y][x].y)) / step;
	i = 0;
	while (i <= step)
	{
		if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
			my_mlx_pixel_put(mlx->image, x + mlx->map->default_x, y + mlx->map->default_y, mlx->map->color[y][x]);
		x += xinc;
		y += yinc;
		i++;
	}
}

void	draw(t_mlx * mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			if (x + 1 < mlx->map->width)
				dda(mlx, x, y);
			if (y + 1 < mlx->map->height)
				dda(mlx, x, y);
			x++;
		}
		y++;
	}
}

/*
dda vs Bresenham
*/
