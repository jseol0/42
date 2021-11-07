/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:44:36 by jseol             #+#    #+#             */
/*   Updated: 2021/11/07 17:52:21 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham2_1(t_mlx *mlx, t_bresenham *b, int x, int y)
{
	int	dx;
	int	dy;
	int	p;

	dx = abs(b->x1 - b->x);
	dy = abs(b->y1 - b->y);
	p = (2 * dx) - dy;
	while (b->y <= b->y1)
	{
		if (b->x > 0 && b->x < WIN_WIDTH && b->y > 0 && b->y < WIN_HEIGHT)
			my_mlx_pixel_put(mlx->image, b->x, b->y, mlx->map->color[y][x]);
		b->y += b->yfactor;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * (dx - dy);
			b->x += b->xfactor;
		}
	}
}

static void	bresenham2_2(t_mlx *mlx, t_bresenham *b, int x, int y)
{
	int	dx;
	int	dy;
	int	p;

	dx = abs(b->x1 - b->x);
	dy = abs(b->y1 - b->y);
	p = (2 * dx) - dy;
	while (b->y >= b->y1)
	{
		if (b->x > 0 && b->x < WIN_WIDTH && b->y > 0 && b->y < WIN_HEIGHT)
			my_mlx_pixel_put(mlx->image, b->x, b->y, mlx->map->color[y][x]);
		b->y += b->yfactor;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * (dx - dy);
			b->x += b->xfactor;
		}
	}
}

void	bresenham2(t_mlx *mlx, t_bresenham *b, int x, int y)
{
	int	dx;
	int	dy;
	int	p;

	dx = abs(b->x1 - b->x);
	dy = abs(b->y1 - b->y);
	p = (2 * dx) - dy;
	if (b->yfactor == 1)
		bresenham2_1(mlx, b, x, y);
	else
		bresenham2_2(mlx, b, x, y);
}
