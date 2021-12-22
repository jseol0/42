/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:01:28 by jseol             #+#    #+#             */
/*   Updated: 2021/12/22 15:40:24 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *s)
{
	perror(s);
	exit(1);
}

void	split_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_free(t_pipe *pipe_x)
{
	int	i;

	if (pipe_x->infile != NULL)
		free(pipe_x->infile);
	if (pipe_x->outfile != NULL)
		free(pipe_x->outfile);
	i = 0;
	while (i < 2)
	{
		if (pipe_x->cmd[i].cmd != NULL)
			split_free(pipe_x->cmd[i].cmd);
		if (pipe_x->cmd[i].path != NULL)
			free(pipe_x->cmd[i].path);
		i++;
	}
	i = 0;
	if (pipe_x->path != NULL)
		split_free(pipe_x->path);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipe_x;
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		ft_memset(&pipe_x, 0, sizeof(t_pipe));
		parse_input_value(&pipe_x, argv, envp);
		check_parsing(&pipe_x);
		if ((pipe(fd)) == ERROR)
		{
			ft_free(&pipe_x);
			ft_error("pipe_x");
		}
		pid = fork();
		pipex(&pipe_x, fd, envp, pid);
	}
	else
		ft_error("Wrong command count");
	return (0);
}
