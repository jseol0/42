/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:23:36 by elim              #+#    #+#             */
/*   Updated: 2022/01/15 21:25:52 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	cnt_s_quote(char *src, size_t *size)
{
	size_t	i;

	i = 1;
	while (src[i] && src[i] != S_QUOTE)
	{
		i++;
		(*size)++;
	}
	return (i);
}

size_t	get_env_key_size(char *src)
{
	size_t	i;
	int		ret;

	ret = ft_isdigit(src[1]);
	if (ret)
		return (1);
	i = 1;
	while (src[i])
	{
		ret = ft_isalnum(src[i]);
		if (!(ret || src[i] == '_'))
			return (i - 1);
		i++;
	}
	return (i - 1);
}

size_t	get_env_value_size(char *src, size_t size, char **env_dup)
{
	size_t	i;
	int		ret;

	i = 0;
	while (env_dup[i])
	{
		ret = ft_strncmp(&src[1], env_dup[i], size);
		if (!ret && env_dup[i][size] == '=')
			return (ft_strlen(env_dup[i] + size + 1));
		i++;
	}
	return (0);
}

size_t	cnt_env(char *src, size_t *size, char **env_dup)
{
	size_t	i;
	char	*status;

	i = 0;
	if (src[1] == '?')
	{
		status = ft_itoa(g_exit_status);
		*size += ft_strlen(status);
		free(status);
		return (1);
	}
	if (!src[1] || src[1] == D_QUOTE)
	{
		(*size)++;
		return (0);
	}
	i = get_env_key_size(src);
	*size += get_env_value_size(src, i, env_dup);
	return (i);
}

size_t	cnt_d_quote(char *src, size_t *size, char **env_dup)
{
	size_t	i;

	i = 1;
	while (src[i] && src[i] != D_QUOTE)
	{
		if (src[i] == '$')
			i += (cnt_env(src + i, size, env_dup) + 1);
		else
		{
			i++;
			(*size)++;
		}
	}
	return (i);
}
