/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:02:32 by elim              #+#    #+#             */
/*   Updated: 2022/01/08 20:45:01 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_strichr(const char *src, char c)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strndup(const char *src, size_t size)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, src, size);
	ret[size] = 0;
	return (ret);
}

t_env	*ft_envnew(char *env_arg)
{
	t_env	*ret;
	size_t	eq_idx;

	ret = (t_env *)malloc(sizeof(t_env));
	if (!ret)
		return (NULL);
	eq_idx = ft_strichr(env_arg, '=');
	ret->key = ft_strndup(env_arg, eq_idx);
	ret->value = ft_strdup(env_arg + eq_idx + 1);
	ret->pre = NULL;
	ret->next = NULL;
	return (ret);
}

t_env	*ft_envlast(t_env *env)
{
	if (!env)
		return (NULL);
	while (env->next)
		env = env->next;
	return (env);
}

void	ft_envadd_back(t_env **env, t_env *new)
{
	t_env	*end;

	end = ft_envlast(*env);
	if (!end)
		*env = new;
	else
	{
		end->next = new;
		new->pre = end;
		new->next = NULL;
	}
}
