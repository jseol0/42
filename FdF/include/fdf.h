/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:01:13 by jseol             #+#    #+#             */
/*   Updated: 2021/11/07 18:01:07 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH		1280
# define WIN_HEIGHT		800
# define WHITE			0xFFFFFF
# define ESC			53

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_bresenham
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int	flag;
	int	xfactor;
	int	yfactor;
}				t_bresenham;

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_map
{
	int		width;
	int		height;
	int		**z;
	int		**color;
	int		max;
	int		min;
	int		size_x;
	int		size_y;
	int		default_x;
	int		default_y;
}				t_map;

typedef struct s_image
{
	void	*image;
	char	*ptr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_image		*image;
	t_vector	**vectors;
}				t_mlx;

void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	*ft_malloc(size_t size, size_t count);
void	read_map(t_map *map, char *map_name);
int		ft_atoi_fdf(const char *str);
int		divide_z(char *split, int col_val);
int		divide_col(char *split, int col_val);
t_mlx	*mlxfree(t_mlx *mlx);
t_mlx	*ft_init(void);
void	draw(t_mlx *mlx, t_bresenham *b);
void	iso_projection(t_mlx *mlx, t_map *map);
void	size_control(t_mlx *mlx, t_map *map);
void	bresenham1(t_mlx *mlx, t_bresenham *b, int x, int y);
void	bresenham2(t_mlx *mlx, t_bresenham *b, int x, int y);
#endif
