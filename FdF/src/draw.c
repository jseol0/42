/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:43:06 by jseol             #+#    #+#             */
/*   Updated: 2021/10/28 18:10:15 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->ptr + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(t_mlx *mlx, t_bresenham *b, int x, int y)
{
	int	dx;
	int	dy;
	int	p;

	dx = (abs(b->x1) - abs(b->x));
	dy = (abs(b->y1) - abs(b->y));
	if (dy > dx)
	{
		p = 2 * (dy - dx);
		while (b->x <= b->x1)
		{
			my_mlx_pixel_put(mlx->image, b->x + mlx->map->default_x,
			 b->y + mlx->map->default_y, mlx->map->color[y][x]);
			b->x++;
			if (p < 0)
				p = p + (2 * dy);
			else
			{
				p = p + (2 * (dy - dx));
				b->y++;
			}
		}
	}
	else
	{
		p = 2 * (dx - dy);
		while (b->y <= b->y1)
		{
			my_mlx_pixel_put(mlx->image, b->x + mlx->map->default_x,
				 b->y + mlx->map->default_y, mlx->map->color[y][x]);
			b->y++;
			if (p < 0)
				p = p + (2 * dy);
			else
			{
				p = p + (2 * (dx - dy));
				b->x++;
			}
		}
	}
}

// void	dda(t_mlx *mlx, t_bresenham *b, int x, int y)
// {
// 	int	dx;
// 	int	dy;
// 	int	step;

// 	dx = (abs(b->x1) - abs(b->x));
// 	dy = (abs(b->y1) - abs(b->y));
// 	if (dx > dy)
// 		step = dx;
// 	else
// 		step = dy;
// 	int	xinc = dx / step;
// 	int	yinc = dy / step;
// 	int i = 0;
// 	while (i <= step)
// 	{

// 	}
// }

void	prepare_bresenham(t_bresenham *b, t_vector **v, int x, int y)
{
	b->x = v[y][x].x;
	b->y = v[y][x].y;
	if (b->flag == 1)
	{
		b->x1 = v[y][x + 1].x;
		b->y1 = v[y][x].y;
	}
	else if (b->flag == -1)
	{
		b->x1 = v[y][x].x;
		b->y1 = v[y + 1][x].y;
	}
}

void	draw(t_mlx *mlx)
{
	int	x;
	int	y;
	t_bresenham	b;

	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			if (x + 1 < mlx->map->width)
			{
				b.flag = 1;
				prepare_bresenham(&b, mlx->vectors, x, y);
				bresenham(mlx, &b, x, y);
			}
			if (y + 1 < mlx->map->height)
			{
				b.flag = -1;
				prepare_bresenham(&b, mlx->vectors, x, y);
				bresenham(mlx, &b, x, y);
			}
			x++;
		}
		y++;
	}
}

/*
dda vs Bresenham
*/
