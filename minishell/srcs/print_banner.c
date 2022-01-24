/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_banner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:15:29 by elim              #+#    #+#             */
/*   Updated: 2022/01/24 16:26:43 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define PATH "/Users/elim/eval/banner"

void	print_banner(void)
{
	int		fd;
	char	*line;

	fd = open(PATH, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
}
