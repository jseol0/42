/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:57:40 by jseol             #+#    #+#             */
/*   Updated: 2022/01/23 18:31:15 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_cmdname(t_cmd *cmd, char ***env, int fd, int pipe_fd[])
{
	if (!cmd->cmd_args[0])
		return (0);
	if ((ft_strncmp("echo", cmd->cmd_args[0], 5)) == 0)
		return (ft_echo(cmd, fd));
	else if ((ft_strncmp("cd", cmd->cmd_args[0], 3)) == 0)
		return (ft_cd(cmd, env));
	else if ((ft_strncmp("pwd", cmd->cmd_args[0], 4)) == 0)
		return (ft_pwd(fd));
	else if ((ft_strncmp("export", cmd->cmd_args[0], 7)) == 0)
		return (ft_export(cmd, env, fd));
	else if ((ft_strncmp("unset", cmd->cmd_args[0], 6)) == 0)
		return (ft_unset(cmd, *env));
	else if ((ft_strncmp("env", cmd->cmd_args[0], 4)) == 0)
		return (ft_env(*env, fd));
	else if ((ft_strncmp("exit", cmd->cmd_args[0], 5)) == 0)
		return (ft_exit(cmd));
	else if (non_builtin(cmd, *env, pipe_fd) == ERROR)
		return (ERROR);
	return (0);
}

static int	get_out_flag(t_cmd *cmd)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < cmd->redir.redir_cnt)
		ret = cmd->redir.redir_flag[i++];
	if (ret == REDIR_R || ret == REDIR_RR)
		return (1);
	else
		return (0);
}

static int	exec_funtion(t_cmd *cmd, char ***env, int pipe_fd[])
{
	int	fd;
	int	out_flag;

	if (cmd->redir.redir_cnt)
	{
		if ((redirect(cmd, pipe_fd)) == ERROR)
			return (ERROR);
	}
	out_flag = get_out_flag(cmd);
	if (cmd->pipe_flag && !out_flag)
		fd = pipe_fd[1];
	else
		fd = STDOUT_FILENO;
	return (check_cmdname(cmd, env, fd, pipe_fd));
}

int	exec(t_cmd *cmd, char ***env)
{
	int		fd[2];
	int		exec_val;
	pid_t	pid;

	pipe(fd);
	exec_val = exec_funtion(cmd, env, fd);
	if (exec_val == ERROR)
		ft_error(cmd);
	else
		g_exit_status = 0;
	dup2(STDIN_BACKUP, STDIN_FILENO);
	dup2(STDOUT_BACKUP, STDOUT_FILENO);
	if (cmd->pipe_flag == 1)
		pid = fork();
	else
		return (g_exit_status);
	if (pid == 0)
		exec_child(cmd, *env, fd);
	else if (pid > 0)
		exec_parents(pid, fd);
	return (g_exit_status);
}
