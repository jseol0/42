/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 07:56:56 by jseol             #+#    #+#             */
/*   Updated: 2021/05/14 17:22:52 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strncat(char *s1, char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (j < len)
	{
		s1[i] = s2[i + j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ret == NULL)
		return (NULL);
	ft_strncat(ret, s1, s1_len);
	free(s1);
	ft_strncat(ret, s2, s2_len);
	return (ret);
}
char		*ft_strdup(char *s)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

size_t		ft_strchr_index(char *s, char c)
{
	size_t	i = 0;;

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
		return (1);
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
	if (*store && (index = ft_strchr_index(*store, '\n')))
		return (ft_newline_line(store, index, line));
	else if (*store)
	{
		*line = *store;
		*store = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*store;
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	size_t 		index;

	index = 0;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (-1);
	while ((read_size = (read(fd, buf, BUFFER_SIZE))) > 0)
	{
		buf[read_size] = '\0';
		store = ft_strjoin(store, buf);
		if (index == ft_strchr_index(store, '\n'))
			// '\n' 전까지는 line에 주고 1 리턴
			return (ft_newline_line(&store, index, line));
	}
	// EOF 를 만났을 때 : 0 or -1 리턴하고 남은 값 line에 넣기
	return (ft_eof_line(&store, line, read_size));
}
