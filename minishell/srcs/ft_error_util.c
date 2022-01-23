/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 04:15:11 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/23 05:00:02 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_err_str(int code)
{
	if (code == ERR_CMD_NOT_FOUND)
		return (STR_CMD_NOT_FOUND);
	else if (code == ERR_NO_SUCH_FILE)
		return (STR_NO_SUCH_FILE);
	else if (code == ERR_TOO_MANY_ARGS)
		return (STR_TOO_MANY_ARGS);
	else if (code == ERR_REDIR_SNTAX)
		return (STR_REDIR_SYNTAX);
	else if (code == ERR_NUM_ARG_REQUIRED)
		return (STR_NUM_ARG_REQUIRED);
	else if (code == ERR_EXPORT)
		return (STR_EXPORT);
	else
		return (STR_UNSET);
}

static void	ft_prrint_err_redir(char *code_src, char *err_token)
{
	write(STDERR_FILENO, code_src, ft_strlen(code_src));
	write(STDERR_FILENO, err_token, ft_strlen(err_token));
	write(STDERR_FILENO, "'\n", 2);
	return ;
}

void	ft_print_err(t_cmd *cmd)
{
	char	*code_src;
	char	*err_token;

	code_src = get_err_str(cmd->err.code);
	if (cmd->err.err_token)
		err_token = cmd->err.err_token;
	else
		err_token = cmd->token[cmd->err.err_idx].cmd;
	write(STDERR_FILENO, "minishell: ", 11);
	if (1 <= cmd->err.code && cmd->err.code <= 3)
	{
		write(STDERR_FILENO, err_token, ft_strlen(err_token));
		if (cmd->err.code == 2 && !ft_strncmp("cd", err_token, 2))
		{
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, cmd->token[cmd->err.err_idx].cmd, \
			ft_strlen(cmd->token[cmd->err.err_idx].cmd));
		}
		write(STDERR_FILENO, code_src, ft_strlen(code_src));
	}
	else if (cmd->err.code == 4)
		ft_prrint_err_redir(code_src, err_token);
	return ;
}
