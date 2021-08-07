/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:01:13 by jseol             #+#    #+#             */
/*   Updated: 2021/07/31 16:37:48 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH		1280
# define WIN_HEIGHT		720
# define WHITE			0xffffff
# define RED			0xFF0000
# define ORANGE			0xFFC31E
# define YELLOW			0xFFFA78
# define GREEN			0x5CE75C
# define PURPLE			0xC73DA3
# define BLUE			0x32B8FF

#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_map
{
	int		width;
	int		height;
	int		**code;
	int		max_depth;
	int		min_depth;
	int		color;
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
void	get_map_code(t_map *map, char *map_name);
void	read_map(t_map *map, char *map_name);
t_image	*new_image(t_mlx *mlx);
t_mlx	*mlxfree(t_mlx *mlx);
t_mlx	*ft_init(void);
void	draw(t_mlx *mlx);
int		get_color(t_map *map, int x, int y);
void	get_depth(t_map *map);


#endif
