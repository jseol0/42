/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:09:21 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/23 05:31:20 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_quote(char *s, int fd)
{
	int	i;

	i = 0;
	if (haveequal(s))
	{
		while (s[i] != '=')
			i++;
		write(fd, s, i + 1);
		write(fd, "\"", 1);
		write(fd, s + (i + 1), ft_strlen(s + (i + 1)));
		write(fd, "\"", 1);
	}
	else
	{
		while (s[i])
			i++;
		write(fd, s, i);
	}
}

static int	isvalidkey_export(char *line)
{
	char	**split;
	char	*key;
	int		i;

	split = ft_split(line, '=');
	key = split[0];
	i = 0;
	if (ft_strlen(key) == 0)
		return (ERROR);
	while (key[i])
	{
		if (ft_isdigit(key[0]))
			return (ERROR);
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (ERROR);
		i++;
	}
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (1);
}

static void	print_export(char **env, int fd)
{
	int		i;
	char	**sorted_env;

	i = 0;
	sorted_env = sort_env(env);
	while (sorted_env[i])
	{
		ft_putstr_fd("declare -x ", fd);
		print_quote(sorted_env[i], fd);
		ft_putchar_fd('\n', fd);
		free(sorted_env[i]);
		i++;
	}
	free(sorted_env);
}

void	add_export(t_cmd *cmd, char ***env, int i)
{
	int	envidx;

	envidx = check_key(*env, cmd->token[i].cmd);
	if (envidx >= 0)
	{
		if (haveequal(cmd->token[i].cmd))
			add_key_env(env, cmd->token[i].cmd, envidx);
	}
	else
		add_env(cmd->token[i].cmd, env);
}

int	ft_export(t_cmd *cmd, char ***env, int fd)
{
	int	i;

	i = 1;
	while (cmd->token[i].cmd && cmd->token[i].redir_flag == 0)
	{
		if (isvalidkey_export(cmd->token[i].cmd))
			add_export(cmd, env, i);
		else
		{
			cmd->err.code = ERR_EXPORT;
			cmd->err.err_token = cmd->token[i].cmd;
			ft_error(cmd);
		}
		i++;
	}
	if (!(cmd->token[1].cmd) || cmd->token[1].redir_flag == 2
		|| cmd->token[1].redir_flag == 4)
		print_export(*env, fd);
	return (0);
}
