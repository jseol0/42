/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:28:26 by jseol             #+#    #+#             */
/*   Updated: 2022/01/04 16:47:12 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# define TRUE 0
# define FALSE 1
# define ERROR -1

typedef struct s_cmd
{
	char		**cmd;
	int			slash;
	char		*path;
	int			error;
}				t_cmd;

typedef struct s_pipe
{
	char		**path;
	char		*infile;
	char		*outfile;
	int			infile_fd;
	int			outfile_fd;
	t_cmd		cmd[2];
}				t_pipe;

void	ft_error(char *s);
void	split_free(char **ptr);
void	ft_free(t_pipe *pipe_x);
void	parse_input_value(t_pipe *pipe_x, char **argv, char **envp);
void	check_parsing(t_pipe *pipe_x);
void	pipex(t_pipe *pipe_x, int *fd, char **envp, pid_t pid);

#endif
