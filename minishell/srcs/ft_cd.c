/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:29:03 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/23 19:32:28 by elim             ###   ########.fr       */
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

static int	chdir_renew_env(char ***env, char *path)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (chdir(getenv(path)) != -1)
	{
		renew_env(env, tmp, "OLDPWD=");
		free(tmp);
		tmp = getcwd(NULL, 0);
		renew_env(env, tmp, "PWD=");
	}
	free(tmp);
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

int	ft_cd(t_cmd *cmd, char ***env)
{
	char	*tmp_path;
	int		ret;

	ret = 0;
	if (!cmd->token[1].cmd)
		return (chdir_renew_env(env, "HOME"));
	if (cmd->token[1].cmd[0] == '~')
	{
		if (cmd->token[1].cmd[1] == 0)
			return (chdir_renew_env(env, "HOME"));
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
