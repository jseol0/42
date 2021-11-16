/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:00:39 by jseol             #+#    #+#             */
/*   Updated: 2021/11/08 19:34:28 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_malloc(size_t size, size_t count)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		exit (1);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

int	key_control(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		mlxfree(mlx);
		exit(0);
	}
	return (0);
}

static void	ft_free(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map->height)
	{
		free(mlx->vectors[i]);
		free(mlx->map->z[i]);
		free(mlx->map->color[i]);
		i++;
	}
	free(mlx->vectors);
	free(mlx->map->z);
	free(mlx->map->color);
}

int	main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_map		map;
	t_bresenham	b;

	if (argc == 1)
		ft_error("Error: no input\n");
	else if (argc > 2)
		ft_error("Error: too many input\n");
	mlx = ft_init();
	if (mlx == NULL)
		ft_error("Error: mlx_init error");
	read_map(&map, argv[1]);
	mlx->map = &map;
	iso_projection(mlx, mlx->map);
	size_control(mlx, mlx->map);
	draw(mlx, &b);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
	ft_free(mlx);
	mlx_key_hook(mlx->window, key_control, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
