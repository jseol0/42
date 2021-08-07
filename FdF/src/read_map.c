/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 16:11:12 by jseol             #+#    #+#             */
/*   Updated: 2021/07/30 08:26:30 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_height(char *map_name, int *width)
{
	char	*line;
	int		ret;
	int		fd;

	ret = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error("Error: can't find map\n");
	while (get_next_line(fd, &line) > 0)
	{
		*width = get_wordcount(line, ' ');
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

void	put_int_to_code(int *code_line, char *line, t_map *map)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	i = 0;
	while (i < map->width && split[i])
	{
		code_line[i] = ft_atoi(split[i]);
		i++;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	get_map_code(t_map *map, char *map_name)
{
	char	*line;
	int		i;
	int		fd;

	map->code = (int **)ft_malloc(sizeof(int *), (map->height + 1));
	i = 0;
	while (i < map->height)
		map->code[i++] = (int *)ft_malloc(sizeof(int), (map->width + 1));
	fd = open(map_name, O_RDONLY);
	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		put_int_to_code(map->code[i], line, map);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	map->code[i] = NULL;
}

void	read_map(t_map *map, char *map_name)
{
	int	width;

	map->height = get_height(map_name, &width);
	map->width = width;
	get_map_code(map, map_name);
	get_depth(map);
}
