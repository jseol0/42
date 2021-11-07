/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:20:34 by jseol             #+#    #+#             */
/*   Updated: 2021/11/07 17:53:47 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham1_1(t_mlx *mlx, t_bresenham *b, int x, int y)
{
	int	dx;
	int	dy;
	int	p;

	dx = abs(b->x1 - b->x);
	dy = abs(b->y1 - b->y);
	p = (2 * dy) - dx;
	while (b->x <= b->x1)
	{
		if (b->x > 0 && b->x < WIN_WIDTH && b->y > 0 && b->y < WIN_HEIGHT)
			my_mlx_pixel_put(mlx->image, b->x, b->y, mlx->map->color[y][x]);
		b->x += b->xfactor;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * (dy - dx);
			b->y += b->yfactor;
		}
	}
}

static void	bresenham1_2(t_mlx *mlx, t_bresenham *b, int x, int y)
{
	int	dx;
	int	dy;
	int	p;

	dx = abs(b->x1 - b->x);
	dy = abs(b->y1 - b->y);
	p = (2 * dy) - dx;
	while (b->x >= b->x1)
	{
		if (b->x > 0 && b->x < WIN_WIDTH && b->y > 0 && b->y < WIN_HEIGHT)
			my_mlx_pixel_put(mlx->image, b->x, b->y, mlx->map->color[y][x]);
		b->x += b->xfactor;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * (dy - dx);
			b->y += b->yfactor;
		}
	}
}

void	bresenham1(t_mlx *mlx, t_bresenham *b, int x, int y)
{
	int	dx;
	int	dy;
	int	p;

	dx = abs(b->x1 - b->x);
	dy = abs(b->y1 - b->y);
	p = (2 * dy) - dx;
	if (b->xfactor == 1)
		bresenham1_1(mlx, b, x, y);
	else
		bresenham1_2(mlx, b, x, y);
}
