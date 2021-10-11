/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:17:52 by jseol             #+#    #+#             */
/*   Updated: 2021/10/01 13:12:11 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_image	*new_image(t_mlx *mlx)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	img->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->size_line,
			 &img->endian);
	return (img);
}

t_mlx	*mlxfree(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->image != NULL)
		free(mlx->image);
	free(mlx);
	return (NULL);
}

t_mlx	*ft_init(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_malloc(sizeof(t_mlx), 1);
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx->image = new_image(mlx);
	if (mlx->mlx == NULL || mlx->window == NULL || mlx->image == NULL)
		return (mlxfree(mlx));
	return (mlx);
}
