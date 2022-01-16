/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 06:50:42 by elim              #+#    #+#             */
/*   Updated: 2022/01/11 17:03:25 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_minishell(int ac, char **av)
{
	(void)ac;
	(void)av;
	init_sig();
	return ;
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

static char	**cpy_envp(char **envp)
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

int	main(int ac, char **av, char **envp)
{
	char	*line;
	char	**env_dup;
	t_cmd	*cmd;
	int		ret;

	init_minishell(ac, av);
	env_dup = cpy_envp(envp);
	while (1)
	{
		line = readline("minishell $ ");
		if (!line)
			break ;
		ret = is_empty_line(line);
		if (!ret)
		{
			add_history(line);
			// cmd = parse_line(env_dup, line);
			// g_exit_status = exec(cmd, env_dup);
			// free cmd
		}
		free(line);
	}
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	return (0);
}
