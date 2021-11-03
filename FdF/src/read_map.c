/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:11:12 by jseol             #+#    #+#             */
/*   Updated: 2021/11/03 17:32:52 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *map_name, int *width)
{
	char	*line;
	int		ret;
	int		fd;
	int		w;

	ret = 0;
	w = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error("Error: can't find map\n");
	while (get_next_line(fd, &line) > 0)
	{
		*width = get_wordcount(line, ' ');
		if (w != 0 && w != *width)
			ft_error("Error: Wrong map\n");
		w = *width;
		ret++;
		free(line);
	}
	free(line);
	close(fd);
	return (ret);
}

int	get_wordcount(char *s, char c)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (!s)
		return (0);
	if (!c)
		return ((int)ft_strlen(s));
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			ret++;
		while (s[i] != c && s[i])
			i++;
	}
	return (ret);
}

void	put_int_to_code(int *z, int* color, char *line, t_map *map)
{
	char	**split;
	int		col_val;
	int		i;

	split = ft_split(line, ' ');
	i = 0;
	while (i < map->width)
	{
		col_val = ft_strchr_index(split[i], ',');
		if (col_val == -1)
		{
			z[i] = ft_atoi_fdf(split[i]);
			color[i] = WHITE;
		}
		else
		{
			z[i] = divide_z(split[i], col_val);
			color[i] = divide_col(split[i], col_val);
		}
		free(split[i]);
		i++;
	}
	free(split);
}

void	get_map_z(t_map *map, char *map_name)
{
	char	*line;
	int		i;
	int		fd;

	map->z = (int **)ft_malloc(sizeof(int *), (map->height));
	i = 0;
	while (i < map->height)
		map->z[i++] = (int *)ft_malloc(sizeof(int), (map->width));
	map->color = (int **)ft_malloc(sizeof(int *), (map->height));
	i = 0;
	while (i < map->height)
		map->color[i++] = (int *)ft_malloc(sizeof(int), (map->width));
	fd = open(map_name, O_RDONLY);
	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		put_int_to_code(map->z[i], map->color[i], line, map);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}

void	read_map(t_map *map, char *map_name)
{
	int	width;

	map->default_x = (WIN_WIDTH / 3);	//(WIN_WIDTH / 2) - (map->width / 2);
	map->default_y = (WIN_HEIGHT / 3) * 2;	//(WIN_HEIGHT / 2) - (map->height / 2);
	map->height = get_height(map_name, &width);
	map->width = width;
	get_map_z(map, map_name);
}
