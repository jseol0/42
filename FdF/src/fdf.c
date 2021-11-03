/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:00:39 by jseol             #+#    #+#             */
/*   Updated: 2021/11/03 16:38:07 by jseol            ###   ########.fr       */
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

int	key_control(int keycode)
{
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	map;

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
	draw(mlx);

	// int i = 0;
	// while (i < mlx->map->height)
	// {
	// 	int j = 0;
	// 	while (j < mlx->map->width)
	// 	{
	// 		printf("y: %d ", i);
	// 		printf("%d %d\n", mlx->vectors[i][j].x, mlx->vectors[i][j].y);
	// 		my_mlx_pixel_put(mlx->image, (mlx->vectors[i][j].x + mlx->map->default_x), (mlx->vectors[i][j].y + mlx->map->default_y), mlx->map->color[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }

	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
	mlx_key_hook(mlx->window, key_control, mlx);
	mlx_loop(mlx->mlx);

	return (0);
}
