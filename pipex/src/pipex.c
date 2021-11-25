/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:51:10 by jseol             #+#    #+#             */
/*   Updated: 2021/11/25 16:50:36 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	redirect_in(t_tmp *tmp)
{
	int	fd;

	fd = open(tmp->infile, O_RDONLY);
	if (fd < 0)
	{
		ft_free(tmp);
		ft_error(tmp->infile);
	}
	dup2(fd, 0);
	close(fd);
}

static void	redirect_out(t_tmp *tmp)
{
	int	fd;

	fd = open(tmp->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_free(tmp);
		ft_error(tmp->outfile);
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

void	pipex(t_tmp *tmp, int *fd, char **envp, pid_t pid)
{
	if (pid > 0)
	{
		waitpid(pid, NULL, WNOHANG);
		set_pipe_exit(fd);
		redirect_out(tmp);
		if (execve(tmp->cmd[1].path, tmp->cmd[1].cmd, envp) == -1)
		{
			ft_free(tmp);
			ft_error("execve");
		}
	}
	else if (pid == 0)
	{
		redirect_in(tmp);
		set_pipe_entry(fd);
		if (tmp->cmd->error != 0)
		{
			if (execve(tmp->cmd[0].path, tmp->cmd[0].cmd, envp) == -1)
			{
				ft_free(tmp);
				ft_error("execve");
			}
		}
	}
}
