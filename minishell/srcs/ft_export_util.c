/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 05:17:18 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/23 05:20:19 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	haveequal(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	check_key(char **env, char *line)
{
	int	keylen;
	int	ret;

	keylen = 0;
	ret = 0;
	if (haveequal(line))
	{
		while (line[keylen] != '=')
			keylen++;
	}
	else
	{
		while (line[keylen])
			keylen++;
	}
	while (env[ret])
	{
		if (ft_strncmp(env[ret], line, keylen) == 0)
			return (ret);
		ret++;
	}
	return (-1);
}

void	add_key_env(char ***env, char *cmd, int envidx)
{
	free((*env)[envidx]);
	(*env)[envidx] = ft_strdup(cmd);
}

int	add_env(char *cmd, char ***env)
{
	int		i;
	int		cnt;
	char	**new;

	cnt = 0;
	while ((*env)[cnt])
		cnt++;
	new = (char **)malloc(sizeof(char *) * (cnt + 2));
	i = 0;
	while ((*env)[i])
	{
		new[i] = ft_strdup((*env)[i]);
		free((*env)[i]);
		i++;
	}
	free(*env);
	new[i] = ft_strdup(cmd);
	new[i + 1] = NULL;
	*env = new;
	return (0);
}

char	**sort_env(char **env)
{
	int		i;
	int		j;
	char	*tmp;
	char	**new;

	new = cpy_envp(env);
	i = 0;
	while (new[i])
	{
		j = i + 1;
		while (new[j])
		{
			if ((ft_strncmp(new[i], new[j], ft_strlen(new[i]))) > 0)
			{
				tmp = new[i];
				new[i] = new[j];
				new[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (new);
}
