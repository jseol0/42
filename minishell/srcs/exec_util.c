/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 03:33:34 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/23 04:55:50 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child(t_cmd *cmd, char **env, int fd[])
{
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	g_exit_status = exec(cmd->next, &env);
	exit(g_exit_status);
}

void	exec_parents(pid_t pid, int fd[])
{
	int		status;

	close(fd[1]);
	close(fd[0]);
	waitpid(pid, &status, 0);
	g_exit_status = status >> 8;
}
