/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:51:10 by jseol             #+#    #+#             */
/*   Updated: 2021/12/22 15:43:08 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	redirect_in(t_pipe *pipe_x)
{
	int	fd;

	fd = open(pipe_x->infile, O_RDONLY);
	if (fd < 0)
	{
		ft_free(pipe_x);
		ft_error(pipe_x->infile);
	}
	dup2(fd, 0);
	close(fd);
}

static void	redirect_out(t_pipe *pipe_x)
{
	int	fd;

	fd = open(pipe_x->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_free(pipe_x);
		ft_error(pipe_x->outfile);
	}
	dup2(fd, 1);
	close(fd);
}

static void	set_pipe_exit(int *fd)
{
	dup2(fd[0], 0);
	close(fd[1]);
}

static void	set_pipe_entry(int *fd)
{
	dup2(fd[1], 1);
	close(fd[0]);
}

void	pipex(t_pipe *pipe_x, int *fd, char **envp, pid_t pid)
{
	if (pid > 0)
	{
		waitpid(pid, NULL, WNOHANG);
		set_pipe_exit(fd);
		redirect_out(pipe_x);
		if (execve(pipe_x->cmd[1].path, pipe_x->cmd[1].cmd, envp) == -1)
		{
			ft_free(pipe_x);
			ft_error("execve");
		}
	}
	else if (pid == 0)
	{
		redirect_in(pipe_x);
		set_pipe_entry(fd);
		if (pipe_x->cmd->error != 0)
		{
			if (execve(pipe_x->cmd[0].path, pipe_x->cmd[0].cmd, envp) == -1)
			{
				ft_free(pipe_x);
				ft_error("execve");
			}
		}
	}
}
