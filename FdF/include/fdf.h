/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:01:13 by jseol             #+#    #+#             */
/*   Updated: 2021/10/07 22:09:33 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH		1440
# define WIN_HEIGHT		840
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define ORANGE			0xFF6600
# define YELLOW			0xFFFF00
# define GREEN			0x00FF00
# define PURPLE			0xFF00FF
# define BLUE			0x0000FF
# define LINE_LEN		50

#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

typedef struct	s_map
{
	int		width;
	int		height;
	int		**z;
	int		**color;
	int		max_depth;
	int		min_depth;
	float	default_x;
	float	default_y;
	t_vector	**vectors;
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
}				t_mlx;

void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	ft_error(char *s);
void	*ft_malloc(size_t size, size_t count);
int		get_height(char *map_name, int *width);
int		get_wordcount(char *s, char c);
void	put_int_to_code(int *code_line, char *line, t_map *map);
void	get_map_z(t_map *map, char *map_name);
void	read_map(t_map *map, char *map_name);
t_image	*new_image(t_mlx *mlx);
t_mlx	*mlxfree(t_mlx *mlx);
t_mlx	*ft_init(void);
void	draw(t_map *map, t_image *img);
void	draw_line(t_map *map, t_image *img, int x1, int y1);
void	draw_color(t_map *map, t_image *img, int x1, int y1);
void	color(t_map *map, int y, int x);
int		get_color(t_map *map);
void	get_depth(t_map *map);
void	rotate_map(t_map *map);
void	projection(t_map *map);


#endif
