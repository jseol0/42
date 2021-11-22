/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:28:26 by jseol             #+#    #+#             */
/*   Updated: 2021/11/22 22:26:24 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
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
}				t_cmd;

typedef struct s_tmp
{
	char		**path;
	char		*infile;
	int			infile_fd;
	char		*outfile;
	int			outfile_fd;
	t_cmd		cmd[2];
}				t_tmp;

void	parse_input_value(t_tmp *tmp, char **argv, char **envp);
void	check_parsing(t_tmp *tmp);
void	pipex(t_tmp *tmp, int *fd, char **envp, pid_t pid);

#endif
