/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:03:48 by elim              #+#    #+#             */
/*   Updated: 2020/11/07 23:40:26 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# define RET_ERROR -1
# define RET_EOF 0
# define RET_READ 1

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char const *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(char *src);
char	*mod_substr(char *src, int i);
char	*mod_strjoin(char *s1, char *s2);

#endif
