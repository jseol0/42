/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:05:47 by elim              #+#    #+#             */
/*   Updated: 2022/01/11 17:26:19 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_flag
{
	int		pipe;
	int		in_quote;
	int		redir;
	int		flag;
}	t_flag;

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*pre;
	struct s_env	*next;
}	t_env;

// typedef struct	s_token
// {
// 	char		*cmd;
// 	char		redir_flag;
// }	t_token;

typedef struct	s_err
{
	int		code;
	int		err_idx;
	char	*err_token;
}	t_err;

typedef struct	s_cmd
{
	char			**cmd_args;
	t_err			err;
	int				redir_flag;
	char			*filename;
	int				pipe_flag;
	int				exit_flag;
	// int				right_flag;
	// char			quote;
	struct s_cmd	*next;
}	t_cmd;

#endif
