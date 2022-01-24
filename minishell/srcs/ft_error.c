/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 01:05:12 by elim              #+#    #+#             */
/*   Updated: 2022/01/23 22:29:50 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_err_num_args(t_cmd *cmd)
{
	char	*err_token;

	err_token = cmd->err.err_token;
	write(STDERR_FILENO, "minishell: exit: ", 17);
	write(STDERR_FILENO, err_token, ft_strlen(err_token));
	write(STDERR_FILENO, STR_NUM_ARG_REQUIRED, 28);
	return ;
}

static void	ft_print_err_export(t_cmd *cmd)
{
	char	*err_token;

	err_token = cmd->err.err_token;
	write(STDERR_FILENO, "minishell: export: `", 20);
	write(STDERR_FILENO, err_token, ft_strlen(err_token));
	write(STDERR_FILENO, STR_EXPORT, 26);
}

static void	ft_print_err_unset(t_cmd *cmd)
{
	char	*err_token;

	err_token = cmd->err.err_token;
	write(STDERR_FILENO, "minishell: unset: `", 19);
	write(STDERR_FILENO, err_token, ft_strlen(err_token));
	write(STDERR_FILENO, STR_EXPORT, 26);
}

static void	get_exit_status(int code)
{
	if (code == ERR_CMD_NOT_FOUND)
		g_exit_status = 127;
	else if (code == ERR_REDIR_SNTAX)
		g_exit_status = 258;
	else if (code == ERR_NUM_ARG_REQUIRED)
		g_exit_status = 255;
	else
		g_exit_status = 1;
	return ;
}

int	ft_error(t_cmd *cmd)
{
	if (1 <= cmd->err.code && cmd->err.code <= 4)
		ft_print_err(cmd);
	else if (cmd->err.code == ERR_NUM_ARG_REQUIRED)
		ft_print_err_num_args(cmd);
	else if (cmd->err.code == ERR_EXPORT)
		ft_print_err_export(cmd);
	else if (cmd->err.code == ERR_UNSET)
		ft_print_err_unset(cmd);
	else
		write(STDERR_FILENO, "minishell: cd: HOME not set\n", 29);
	get_exit_status(cmd->err.code);
	return (0);
}
