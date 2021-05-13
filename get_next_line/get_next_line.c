/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 07:56:56 by jseol             #+#    #+#             */
/*   Updated: 2021/05/13 16:24:01 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strnncat(char *s1, char *s2, size_t len)
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

int				get_next_line(int fd, char **line)
{
	static char	*store;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_size;
	size_t 		i;

	i = 0;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1);
		return (-1);
	while (read_size = (read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		store = ft_strjoin(store, buf);
		if (i = ft_strchr_index(store, '\n'))	//strchr 함수 활용해서 인덱스 리턴
			// '\n' 전까지는 line에 주고 1 리턴
			return (ft_newline_line(store, i, line));
	}
	// EOF 를 만났을 때 : 0 or -1 리턴하고 남은 값 line에 넣기
	return (ft_eof_line(store, line));
}
