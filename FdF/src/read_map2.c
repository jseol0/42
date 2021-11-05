/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:10:08 by jseol             #+#    #+#             */
/*   Updated: 2021/11/05 20:13:19 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_fdf(const char *str)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	ret = 0;
	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		ret *= 10;
		ret += (str[i] - '0') * sign;
		i++;
	}
	if (str[i] && ft_isdigit(str[i]) == 0)
		ft_error("Error: Wrong map\n");

	return (ret);
}

int		divide_z(char *split, int col_val)
{
	char	*z;
	int		ret;
	size_t	len;

	len = ft_strlen(split);
	z = (char *)ft_malloc(sizeof(char), len);
	z = ft_strncpy(z, split, col_val);
	ret = ft_atoi_fdf(z);
	free(z);

	return (ret);
}

int		divide_col(char *split, int col_val)
{
	char	*col;
	int		ret;
	size_t	len;

	len = ft_strlen(split);
	col = (char *)ft_malloc(sizeof(char), len);
	col = ft_strcpy(col, split + col_val + 3);
	ret = ft_atoi_base(col, "0123456789ABCDEF");
	free(col);

	return (ret);
}

/*
void	get_depth(t_map *map)
{
	t_map	cur;
	int	min;
	int	max;
	int	depth;

	min = 2147483647;
	max = -2147483648;
	cur.height = 0;
	while (cur.height < map->height)
	{
		cur.width = 0;
		while (cur.width < map->width)
		{
			depth = map->z[cur.height][cur.width];
			if (depth < min)
				min = depth;
			if (depth > max)
				max = depth;
			cur.width++;
		}
		cur.height++;
	}
	map->min_depth = min;
	map->max_depth = max;
}
*/
