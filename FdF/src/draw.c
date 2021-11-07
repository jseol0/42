/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:43:06 by jseol             #+#    #+#             */
/*   Updated: 2021/11/07 18:03:48 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->ptr + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	bresenham(t_mlx *mlx, t_bresenham *b, int x, int y)
{
	int	dx;
	int	dy;

	dx = abs(b->x1 - b->x);
	dy = abs(b->y1 - b->y);
	if (dx > dy)
		bresenham1(mlx, b, x, y);
	else
		bresenham2(mlx, b, x, y);
}

static void	prepare_bresenham(t_bresenham *b, t_vector **v, int x, int y)
{
	b->x = v[y][x].x;
	b->y = v[y][x].y;
	if (b->flag == 1)
	{
		b->x1 = v[y][x + 1].x;
		b->y1 = v[y][x + 1].y;
	}
	else if (b->flag == -1)
	{
		b->x1 = v[y + 1][x].x;
		b->y1 = v[y + 1][x].y;
	}
	if (b->x1 < b->x)
		b->xfactor = -1;
	else
		b->xfactor = 1;
	if (b->y1 < b->y)
		b->yfactor = -1;
	else
		b->yfactor = 1;
}

void	draw(t_mlx *mlx, t_bresenham *b)
{
	int			x;
	int			y;

	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			if (x + 1 < mlx->map->width)
			{
				b->flag = 1;
				prepare_bresenham(b, mlx->vectors, x, y);
				bresenham(mlx, b, x, y);
			}
			if (y + 1 < mlx->map->height)
			{
				b->flag = -1;
				prepare_bresenham(b, mlx->vectors, x, y);
				bresenham(mlx, b, x, y);
			}
			x++;
		}
		y++;
	}
}
