/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 21:28:13 by jseol             #+#    #+#             */
/*   Updated: 2021/07/30 08:26:02 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(t_map *map, int x, int y)
{
	int	max;
	int	min;
	int	color;
	int	cur;

	max = map->max_depth;
	min = map->min_depth;
	color = WHITE;
	cur = map->code[y][x];
	if (max >= cur  && cur > (max / 3) * 2)
		color = RED;
	else if ((max / 3) * 2 >= cur && cur > max / 3)
		color = ORANGE;
	else if (max / 3 >= cur && cur > 0)
		color = YELLOW;
	else if (0 > cur  && cur >= min / 3)
		color = GREEN;
	else if (min / 3 > cur && cur >= (min / 3) * 2)
		color = BLUE;
	else if ((min / 3) * 2 > cur && cur >= min)
		color = PURPLE;
	return (color);
}
