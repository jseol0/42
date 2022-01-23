/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:22:32 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/23 04:34:34 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	isvalidkey_unset(char *key)
{
	int	i;

	i = 0;
	if (ft_strlen(key) == 0)
		return (0);
	while (key[i])
	{
		if (ft_isdigit(key[0]))
			return (0);
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	ft_delete_env(int remove_idx, char **env)
{
	free(env[remove_idx]);
	while (env[remove_idx])
	{
		env[remove_idx] = env[remove_idx + 1];
		remove_idx++;
	}
}

int	ft_unset(t_cmd *cmd, char **env)
{
	int	i;
	int	remove_idx;

	i = 1;
	while (cmd->token[i].cmd && cmd->token[i].redir_flag == 0)
	{
		if (isvalidkey_unset(cmd->token[i].cmd))
		{
			remove_idx = check_key(env, cmd->token[i].cmd);
			if (remove_idx >= 0)
				ft_delete_env(remove_idx, env);
		}
		else
		{
			cmd->err.code = ERR_UNSET;
			cmd->err.err_token = cmd->token[i].cmd;
			ft_error(cmd);
		}
		i++;
	}
	return (0);
}
