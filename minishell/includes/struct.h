/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:05:47 by elim              #+#    #+#             */
/*   Updated: 2022/01/23 15:29:09 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_flag
{
	int		pipe;
	int		in_quote;
	int		redir;
	int		flag;
}	t_flag;

typedef struct s_token
{
	char		*cmd;
	int			redir_flag;
}	t_token;

typedef struct s_err
{
	int		code;
	int		err_idx;
	char	*err_token;
}	t_err;

typedef struct s_redir
{
	int		redir_cnt;
	int		*redir_flag;
	char	**redir;
	char	**filename;
}	t_redir;

typedef struct s_cmd
{
	t_token			*token;
	char			**cmd_args;
	t_err			err;
	t_redir			redir;
	int				pipe_flag;
	int				exit_flag;
	struct s_cmd	*next;
}	t_cmd;

#endif
