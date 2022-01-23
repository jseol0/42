/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:24:34 by elim              #+#    #+#             */
/*   Updated: 2022/01/16 16:07:43 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_key(char *src)
{
	char	*ret;

	ret = ft_substr(src, 1, get_env_key_size(src));
	return (ret);
}

char	*get_env_value(char *key, char **env_dup)
{
	size_t	i;
	int		ret;
	char	is_equal;

	i = 0;
	while (env_dup[i])
	{
		ret = ft_strncmp(key, env_dup[i], ft_strlen(key));
		is_equal = env_dup[i][ft_strlen(key)];
		if (is_equal != '=')
			is_equal = 0;
		if (!ret && is_equal)
			return (env_dup[i] + ft_strlen(key) + 1);
		i++;
	}
	return ("");
}

size_t	malloc_env(char *src, char **cmd, char **env_dup)
{
	size_t	i;
	size_t	value_size;
	char	*key;
	char	*value;

	if (src[1] == '?')
		return (malloc_env_case_exit_status(cmd));
	if (!src[1] || src[1] == D_QUOTE)
	{
		**cmd = '$';
		(*cmd)++;
		return (0);
	}
	i = get_env_key_size(src);
	key = get_env_key(src);
	value = get_env_value(key, env_dup);
	value_size = ft_strlen(value);
	ft_memcpy(*cmd, value, value_size);
	*cmd += value_size;
	free(key);
	return (i);
}

size_t	malloc_d_quote(char *src, char **cmd, char **env_dup)
{
	size_t	i;

	i = 1;
	while (src[i] && src[i] != D_QUOTE)
	{
		if (src[i] == '$')
			i += (malloc_env(&src[i], cmd, env_dup) + 1);
		else
		{
			**cmd = src[i];
			(*cmd)++;
			i++;
		}
	}
	return (i);
}

size_t	malloc_s_quote(char *src, char **cmd)
{
	size_t	i;
	size_t	cmd_size;

	i = 1;
	cmd_size = 0;
	while (src[i] && src[i] != S_QUOTE)
	{
		i++;
		cmd_size++;
	}
	ft_memcpy(*cmd, src + 1, cmd_size);
	*cmd += cmd_size;
	return (i);
}
