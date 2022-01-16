/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:36:29 by elim              #+#    #+#             */
/*   Updated: 2022/01/08 20:04:56 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_envp(char **envp)
{
	t_env	*head;
	t_env	*new;
	int		i;

	head = NULL;
	i = 0;
	while (envp[i])
	{
		new = ft_envnew(envp[i]);
		if (!new)
			return (NULL); // handle error
		ft_envadd_back(&head, new);
		i++;
	}
	return (head);
}
