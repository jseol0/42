/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:00:39 by jseol             #+#    #+#             */
/*   Updated: 2021/07/25 20:44:50 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->ptr + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

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
	draw(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
