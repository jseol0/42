/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 06:33:11 by elim              #+#    #+#             */
/*   Updated: 2022/01/13 18:38:54 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include "const.h"
# include "struct.h"

int			g_exit_status;

/*
signal
*/
void		init_sig(void);

/*
env
*/
t_env		*get_envp(char **envp);

/*
env utils
*/
t_env		*ft_envnew(char *env_arg);
t_env		*ft_envlast(t_env *env);
void		ft_envadd_back(t_env **env, t_env *new);

/*
parse line
*/
t_cmd		*parse_line(char **env_dup, char *line);
void		handle_quote_flag(t_flag *flag, int c);

/*
cmd utils
*/
t_cmd		*ft_cmdlast(t_cmd *cmd);
void		ft_cmdadd_back(t_cmd **cmd, t_cmd *new);


#endif
