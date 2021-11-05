/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:01:13 by jseol             #+#    #+#             */
/*   Updated: 2021/11/05 23:53:01 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH		1280
# define WIN_HEIGHT		800
# define WHITE			0xFFFFFF
# define LINE_LEN		50
# define ESC			53

#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>

typedef struct	s_bresenham
{
	int	x;
	int	y;
	int	x1;
	int	y1;
	int		flag;
}				t_bresenham;

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct	s_map
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


typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_image		*image;
	t_vector	**vectors;
}				t_mlx;

void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	*ft_malloc(size_t size, size_t count);
int		get_height(char *map_name, int *width);
int		get_wordcount(char *s, char c);
void	put_int_to_code(int *z, int* color, char *line, t_map *map);
int		ft_atoi_fdf(const char *str);
void	get_map_z(t_map *map, char *map_name);
void	read_map(t_map *map, char *map_name);
t_image	*new_image(t_mlx *mlx);
t_mlx	*mlxfree(t_mlx *mlx);
t_mlx	*ft_init(void);
void	draw(t_mlx *mlx);
void	draw_line(t_map *map, t_image *img, int x1, int y1);
void	draw_color(t_map *map, t_image *img, int x1, int y1);
int		divide_z(char *split, int col_val);
int		divide_col(char *split, int col_val);
void	get_depth(t_map *map);
void	rotate_map(t_map *map);
void	iso_projection(t_mlx *mlx, t_map *map);
void	size_control(t_mlx *mlx, t_map *map);

#endif
