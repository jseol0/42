/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:05:07 by elim              #+#    #+#             */
/*   Updated: 2022/01/23 19:42:50 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_new_shlvl(char *env_shlvl)
{
	int		shlvl;
	char	*tmp;
	char	*ret;

	shlvl = ft_atoi(env_shlvl + 6) + 1;
	free(env_shlvl);
	tmp = ft_itoa(shlvl);
	ret = ft_strjoin("SHLVL=", tmp);
	free(tmp);
	return (ret);
}

static char	*get_new_pwd(char *env_pwd)
{
	char	*pwd;
	char	*ret;

	free(env_pwd);
	pwd = getcwd(NULL, 0);
	ret = ft_strjoin("PWD=", pwd);
	free(pwd);
	return (ret);
}

void	handle_envp(char ***env)
{
	int		i;

	i = 0;
	while ((*env)[i])
	{
		if (!ft_strncmp("SHLVL=", (*env)[i], 6))
			(*env)[i] = get_new_shlvl((*env)[i]);
		else if (!ft_strncmp("PWD=", (*env)[i], 4))
			(*env)[i] = get_new_pwd((*env)[i]);
		i++;
	}
	return ;
}
