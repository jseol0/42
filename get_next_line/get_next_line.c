/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 07:56:56 by jseol             #+#    #+#             */
/*   Updated: 2021/05/15 17:12:07 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strchr_index(char *s, char c)
{
	size_t	i = 0;;

	if (s == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_newline_line(char **store, size_t index, char **line)
{
	size_t	len;
	char	*tmp;

	(*store)[index] = '\0';
	*line = ft_strdup(*store);
	len = ft_strlen(*store + index + 1);
	if (len == 0)
	{
		free(*store);
		*store = 0;
		return (0);
	}
	tmp = ft_strdup(*store + index + 1);
	free(*store);
	*store = tmp;
	return (1);
}

int			ft_eof_line(char **store, char **line, int read_size)
{
	size_t index;

	if (read_size < 0)
		return (-1);
	// store 에 남은 \n 이하 처리
	if (*store && (index = ft_strchr_index(*store, '\n')) >= 0)
		return (ft_newline_line(store, index, line));
	else if (*store)
	{
		*line = *store;
		free(*store);
		*store = 0;
		return (0);
	}
	*line = ft_strdup("");
	free(*store);
	*store = 0;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*store = NULL;
	char		buf[BUFFER_SIZE + 1];
	int			read_size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	while (!ft_strchr_index(store, '\n') && (read_size = (read(fd, buf, BUFFER_SIZE))) > 0)
	{
		buf[read_size] = '\0';
		store = ft_strjoin(store, buf);
	}
	return (ft_eof_line(&store, line, read_size));
}
