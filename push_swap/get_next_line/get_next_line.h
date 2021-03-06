/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 08:34:18 by jseol             #+#    #+#             */
/*   Updated: 2021/07/13 17:47:52 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_gnl_strlen(char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
char	*ft_gnl_strdup(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		ft_strchr_index(char *s, char c);
int		ft_newline_line(char **store, size_t index, char **line);
int		ft_eof_line(char **store, char **line, int read_size);
int		get_next_line(int fd, char **line);

#endif
