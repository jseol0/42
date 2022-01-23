/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 06:50:42 by elim              #+#    #+#             */
/*   Updated: 2022/01/23 20:20:01 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_minishell(char **env_dup)
{
	int	i;

	i = 0;
	while (env_dup[i])
		free(env_dup[i++]);
	free(env_dup);
	ft_putstr_fd("\x1b[1A", STDOUT_FILENO);
	ft_putstr_fd("\033[12C", STDOUT_FILENO);
	ft_putstr_fd("exit\n", STDOUT_FILENO);
}

static int	is_empty_line(char *line)
{
	if (!*line)
		return (1);
	while (*line)
	{
		if (!(('\t' <= *line && *line <= '\r') || *line == ' '))
			return (0);
		line++;
	}
	return (1);
}

char	**cpy_envp(char **envp)
{
	char	**ret;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		ret[i] = ft_strdup(envp[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

static void	init_minishell(int ac, char **av, char ***env_dup, char **envp)
{
	print_banner();
	(void)ac;
	(void)av;
	init_sig();
	*env_dup = cpy_envp(envp);
	handle_envp(env_dup);
	dup2(STDIN_FILENO, STDIN_BACKUP);
	dup2(STDOUT_FILENO, STDOUT_BACKUP);
	return ;
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	char	**env_dup;
	t_cmd	*cmd;
	int		ret;

	init_minishell(ac, av, &env_dup, envp);
	while (1)
	{
		envp = env_dup;
		line = readline("minishell $ ");
		if (!line)
			break ;
		ret = is_empty_line(line);
		if (!ret)
		{
			add_history(line);
			cmd = parse_line(env_dup, line);
			g_exit_status = exec(cmd, &env_dup);
			ft_free_cmd(cmd);
		}
		free(line);
	}
	exit_minishell(env_dup);
	return (0);
}
