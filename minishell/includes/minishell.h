/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 06:33:11 by elim              #+#    #+#             */
/*   Updated: 2022/01/23 20:19:39 by elim             ###   ########.fr       */
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
main
*/
void		handle_envp(char ***env);
void		print_banner(void);

/*
signal
*/
void		init_sig(void);

/*
parse line
*/
t_cmd		*parse_line(char **env_dup, char *line);
void		handle_quote_flag(t_flag *flag, int c);

/*
cmd
*/
t_cmd		*ft_cmdnew(char *line, char **env_dup, \
					int exit_flag, int pipe_flag);
size_t		get_split_size(char *line);
t_token		*malloc_token(char *line, size_t size);
t_token		*parse_cmd(t_token *token, char **env_dup);
t_redir		get_redir_struct(t_token *token);
char		**get_cmd_args(t_token *token);

/*
cmd utils
*/
t_cmd		*ft_cmdlast(t_cmd *cmd);
void		ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
void		handle_flag_up(t_flag *flag, char *line, int i, int *cnt);
size_t		case_redir(char *line);
size_t		cnt_s_quote(char *src, size_t *size);
size_t		get_env_key_size(char *src);
size_t		get_env_value_size(char *src, size_t size, char **env_dup);
size_t		cnt_env(char *src, size_t *size, char **env_dup);
size_t		cnt_d_quote(char *src, size_t *size, char **env_dup);
char		*get_env_key(char *src);
char		*get_env_value(char *key, char **env_dup);
size_t		malloc_env(char *src, char **cmd, char **env_dup);
size_t		malloc_env_case_exit_status(char **cmd);
size_t		malloc_d_quote(char *src, char **cmd, char **env_dup);
size_t		malloc_s_quote(char *src, char **cmd);
size_t		ft_tokensize(t_token *token);
char		**cpy_envp(char **envp);

/*
exec
*/
int			exec(t_cmd *cmd, char ***env);
void		exec_parents(pid_t pid, int fd[]);
void		exec_child(t_cmd *cmd, char **env, int fd[]);

/*
builtin
*/
int			ft_cd(t_cmd *cmd, char ***env);
int			ft_echo(t_cmd *cmd, int fd);
int			ft_env(char **env, int fd);
int			ft_exit(t_cmd *cmd);
int			ft_export(t_cmd *cmd, char ***env, int fd);
char		**sort_env(char **env);
int			add_env(char *cmd, char ***env);
void		add_key_env(char ***env, char *cmd, int envidx);
int			haveequal(char *line);
int			check_key(char **env, char *line);
int			ft_pwd(int fd);
int			ft_unset(t_cmd *cmd, char **env);

/*
non builtin
*/
int			non_builtin(t_cmd *cmd, char **env, int pipe_fd[]);

/*
redir
*/
int			redirect(t_cmd *cmd, int pipe_fd[]);
int			file_check(t_cmd *cmd, t_redir redir);
int			err_redirect(t_cmd *cmd, int i);

/*
builtin utils
*/
int			check_key(char **env, char *line);

/*
free & error
*/
void		ft_free_cmd(t_cmd *cmd);
void		*ft_free_token(t_token *token, int size);
void		ft_free_split(char **split);
int			ft_error(t_cmd *cmd);
int			check_digit(t_cmd *cmd);
long long	ft_atoi_exit(const char *str);
void		ft_print_err(t_cmd *cmd);

#endif
