/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:03:45 by elim              #+#    #+#             */
/*   Updated: 2021/10/28 16:08:42 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ret_next_line(char **line, char **rest, int fd, int i)
{
	char	*tmp;

	*line = mod_substr(rest[fd], i);
	tmp = ft_strdup(rest[fd] + i + 1);
	free(rest[fd]);
	rest[fd] = tmp;
	return (RET_READ);
}

int	ret_handle(char **line, char **rest, int fd, int read_size)
{
	if (read_size < 0)
		return (RET_ERROR);
	if (rest[fd])
	{
		*line = rest[fd];
		rest[fd] = 0;
		return (RET_EOF);
	}
	*line = ft_strdup("");
	return (RET_EOF);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (RET_ERROR);
	i = is_newline(rest[fd]);
	if (rest[fd] && i >= 0)
		return (ret_next_line(line, rest, fd, i));
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = 0;
		rest[fd] = mod_strjoin(rest[fd], buf);
		i = is_newline(rest[fd]);
		if (i >= 0)
			return (ret_next_line(line, rest, fd, i));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (ret_handle(line, rest, fd, read_size));
}
