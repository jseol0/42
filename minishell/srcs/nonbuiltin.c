/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonbuiltin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:50:17 by jseol             #+#    #+#             */
/*   Updated: 2022/01/23 04:41:57 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	non_builtin_exec(t_cmd *cmd, char **env, int pipe_fd[])
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (cmd->pipe_flag == 1)
			dup2(pipe_fd[1], 1);
		execve(cmd->cmd_args[0], cmd->cmd_args, env);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		g_exit_status = status >> 8;
	}
	return (0);
}

static char	**find_path(char **envp)
{
	int		i;
	char	*tmp;
	char	**ret;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_strdup(envp[i] + 5);
			ret = ft_split(tmp, ':');
			free(tmp);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

static void	set_cmd_arg_0(t_cmd *cmd, char *path_cmd, char *tmp, char **split)
{
	ft_free_split(split);
	free(tmp);
	free(cmd->cmd_args[0]);
	cmd->cmd_args[0] = path_cmd;
	return ;
}

static int	check_cmdpath(t_cmd *cmd, char **env, int p_fd[], struct stat *buf)
{
	char	**split_path;
	char	*tmp_path;
	char	*path_cmd;
	int		i;

	split_path = find_path(env);
	cmd->err.err_token = cmd->cmd_args[0];
	if (!split_path)
		return (ERROR);
	i = 0;
	while (split_path[i])
	{
		tmp_path = ft_strjoin(split_path[i], "/");
		path_cmd = ft_strjoin(tmp_path, cmd->cmd_args[0]);
		if (stat(path_cmd, buf) == 0)
		{
			set_cmd_arg_0(cmd, path_cmd, tmp_path, split_path);
			return (non_builtin_exec(cmd, env, p_fd));
		}
		free(tmp_path);
		free(path_cmd);
		i++;
	}
	ft_free_split(split_path);
	return (ERROR);
}

int	non_builtin(t_cmd *cmd, char **env, int pipe_fd[])
{
	int			ret;
	struct stat	buf;

	if (stat(cmd->cmd_args[0], &buf) == 0)
		ret = (non_builtin_exec(cmd, env, pipe_fd));
	else
		ret = check_cmdpath(cmd, env, pipe_fd, &buf);
	if (ret == ERROR)
	{
		cmd->err.code = ERR_CMD_NOT_FOUND;
		return (ERROR);
	}
	return (0);
}
