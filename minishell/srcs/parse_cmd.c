/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:20:24 by elim              #+#    #+#             */
/*   Updated: 2022/01/20 17:55:29 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_redir(char *src, int *redir_flag)
{
	int	ret_l;
	int	ret_r;
	int	ret_ll;
	int	ret_rr;

	ret_l = ft_strncmp(src, "<", ft_strlen(src));
	ret_r = ft_strncmp(src, ">", ft_strlen(src));
	ret_ll = ft_strncmp(src, "<<", ft_strlen(src));
	ret_rr = ft_strncmp(src, ">>", ft_strlen(src));
	if (!ret_l)
		*redir_flag = REDIR_L;
	else if (!ret_r)
		*redir_flag = REDIR_R;
	else if (!ret_ll)
		*redir_flag = REDIR_LL;
	else if (!ret_rr)
		*redir_flag = REDIR_RR;
	else
		*redir_flag = REDIR_SYNTAX_ERR;
}

static char	is_closed_quote(char *src, char quote)
{
	size_t	i;

	i = 1;
	while (src[i] && src[i] != quote)
		i++;
	if (src[i] == quote)
		return (quote);
	return (0);
}

static size_t	get_token_size(char *src, char **env_dup)
{
	size_t	size;
	size_t	i;
	char	q_close;

	size = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] == D_QUOTE || src[i] == S_QUOTE)
			q_close = is_closed_quote(src + i, src[i]);
		if (src[i] == D_QUOTE && q_close == D_QUOTE)
			i += cnt_d_quote(src + i, &size, env_dup);
		else if (src[i] == S_QUOTE && q_close == S_QUOTE)
			i += cnt_s_quote(src + i, &size);
		else if (src[i] == '$')
			i += cnt_env(src + i, &size, env_dup);
		else if (src[i])
			size++;
		i++;
	}
	return (size);
}

static void	set_token(char *src, char *cmd, char **env_dup)
{
	char	*tmp;
	size_t	i;
	int		q_close;

	tmp = cmd;
	i = 0;
	while (src[i])
	{
		q_close = 0;
		if (src[i] == D_QUOTE || src[i] == S_QUOTE)
			q_close = is_closed_quote(src + i, src[i]);
		if (src[i] == D_QUOTE && q_close == D_QUOTE)
			i += malloc_d_quote(src + i, &tmp, env_dup);
		else if (src[i] == S_QUOTE && q_close == S_QUOTE)
			i += malloc_s_quote(src + i, &tmp);
		else if (src[i] == '$')
			i += malloc_env(src + i, &tmp, env_dup);
		else if (src[i])
		{
			*tmp = src[i];
			tmp++;
		}
		i++;
	}
	*tmp = 0;
}

t_token	*parse_cmd(t_token *token, char **env_dup)
{
	char	*tmp;
	int		i;
	size_t	size;

	i = 0;
	while (token[i].cmd)
	{
		tmp = NULL;
		size = get_token_size(token[i].cmd, env_dup);
		token[i].redir_flag = 0;
		if (token[i].cmd[0] == '<' || token[i].cmd[0] == '>')
			handle_redir(token[i].cmd, &(token[i].redir_flag));
		tmp = (char *)malloc(sizeof(char) * (size + 1));
		if (!tmp)
			return ((t_token *)ft_free_token(token, ft_tokensize(token)));
		set_token(token[i].cmd, tmp, env_dup);
		free(token[i].cmd);
		token[i].cmd = tmp;
		i++;
	}
	return (token);
}
