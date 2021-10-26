/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:43:06 by jseol             #+#    #+#             */
/*   Updated: 2021/10/23 17:54:05 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->ptr + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void	dda(t_image *img, t_map *map, int x, int y)
{
	int	i;
	float	step;
	float	xinc;
	float	yinc;
	t_vector	**v;

	v = map->vectors;
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
			my_mlx_pixel_put(img, x + map->default_x, y +  map->default_y, map->color[y][x]);
		x += xinc;
		y += yinc;
		i++;
	}
}

void	draw(t_map *map, t_image *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x + 1 < map->width)
				dda(img, map, x, y);
			if (y + 1 < map->height)
				dda(img, map, x, y);
			x++;
		}
		y++;
	}
}

/*
x, y 길이 늘려주기 - 전체 윈도우의 중앙에 맞추기
plus_x = (WIN_WIDTH / 2) - (mlx->map->width / 2)
plus_y = (WIN_HEIGHT / 2) - (mlx->map->height / 2)

나중에 픽셀 찍을때
my_mlx_pixel_put(img, x + plus_x, y + plus_y, color)
*/