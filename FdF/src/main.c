/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:00:39 by jseol             #+#    #+#             */
/*   Updated: 2021/10/26 15:46:06 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 1);
	exit(1);
}

void	*ft_malloc(size_t size, size_t count)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		exit (1);
	ft_bzero(ptr, (count * size));
	return (ptr);
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
	iso_projection(mlx->map);
	// draw(mlx->map, mlx->image);
	// mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
	// mlx_loop(mlx->mlx);

	int i = 0;
	while (i < mlx->map->height)
	{
		int j = 0;
		while (j < mlx->map->width)
		{
			printf("%f %f ", mlx->map->vectors[i][j].x, mlx->map->vectors[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
