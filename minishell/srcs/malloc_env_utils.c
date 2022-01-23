/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:32:03 by elim              #+#    #+#             */
/*   Updated: 2022/01/15 21:34:44 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	malloc_env_case_exit_status(char **cmd)
{
	char	*status;

	status = ft_itoa(g_exit_status);
	ft_memcpy(*cmd, status, ft_strlen(status));
	*cmd += ft_strlen(status);
	free(status);
	return (1);
}
