/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:51:10 by jseol             #+#    #+#             */
/*   Updated: 2021/11/20 17:25:12 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	redirect_in(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		perror("infile");
		// return (-1);
	}
	dup2(fd, 0);
	close(fd);
}

static void	redirect_out(char *outfile)
{
	int fd;

	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("outfile");
		// return (-1);
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
		redirect_out(tmp->outfile);
		set_pipe_exit(fd);
		execve(tmp->cmd[1].path, tmp->cmd[1].cmd, envp);
	}
	else if (pid == 0)
	{
		redirect_in(tmp->infile);
		set_pipe_entry(fd);
		execve(tmp->cmd[0].path, tmp->cmd[0].cmd, envp);
	}
}
