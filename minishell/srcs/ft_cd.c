/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:29:03 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/23 22:32:39 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static void	renew_env(char ***env, char *src, char *flag)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*env)[i])
	{
		if (!ft_strncmp(flag, (*env)[i], ft_strlen(flag)))
		{
			tmp = ft_strjoin(flag, src);
			free((*env)[i]);
			(*env)[i] = tmp;
		}
		i++;
	}
}

static int	chdir_renew_env(char ***env, char *path, int flag)
{
	char	*tmp;
	char	*home_path;

	tmp = getcwd(NULL, 0);
	if (flag)
		home_path = getenv(path);
	else
		home_path = get_env_value("HOME", *env);
	if (chdir(home_path) == -1)
	{
		free(tmp);
		return (-1);
	}
	else
	{
		renew_env(env, tmp, "OLDPWD=");
		free(tmp);
		tmp = getcwd(NULL, 0);
		renew_env(env, tmp, "PWD=");
		free(tmp);
	}
	return (0);
}

static int	cd_error_check(t_cmd *cmd, char ***env)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (chdir(cmd->token[1].cmd) == -1)
	{
		cmd->err.code = ERR_NO_SUCH_FILE;
		cmd->err.err_token = cmd->token[0].cmd;
		cmd->err.err_idx = 1;
		free(tmp);
		return (1);
	}
	else
	{
		renew_env(env, tmp, "OLDPWD=");
		free(tmp);
		tmp = getcwd(NULL, 0);
		renew_env(env, tmp, "PWD=");
		free(tmp);
	}
	return (0);
}

static int	cd_no_env_home(t_cmd *cmd)
{
	cmd->err.code = ERR_NO_ENV_HOME;
	return (1);
}

int	ft_cd(t_cmd *cmd, char ***env)
{
	char	*tmp_path;
	int		ret;

	ret = 0;
	if (!cmd->token[1].cmd)
	{
		if (chdir_renew_env(env, "HOME", 0) == -1)
			return (cd_no_env_home(cmd));
		return (0);
	}
	if (cmd->token[1].cmd[0] == '~')
	{
		if (cmd->token[1].cmd[1] == 0)
			return (chdir_renew_env(env, "HOME", 1));
		else if (cmd->token[1].cmd[1] == '/')
		{
			tmp_path = cmd->token[1].cmd;
			cmd->token[1].cmd = ft_strjoin(getenv("HOME"),
					cmd->token[1].cmd + 1);
			free(tmp_path);
		}
	}
	return (cd_error_check(cmd, env));
}
