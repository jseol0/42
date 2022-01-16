/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elim <elim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:48:19 by elim              #+#    #+#             */
/*   Updated: 2022/01/13 19:23:26 by elim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_tmpsize(char **tmp)
{
	int	i;

	i = 0;
	if (tmp)
	{
		if (tmp[i])
			i++;
	}
	return (i);
}

void	*ft_free_tmp(char **srcs, int size)
{
	int	i;

	i = 0;
	if (srcs)
	{
		while (i < size && srcs[i])
			free(srcs[i++]);
		free(srcs);
	}
	return (NULL);
}

static void	init_flag(t_flag *flag, int *i)
{
	flag->flag = 0;
	flag->in_quote = 0;
	*i = 0;
	return ;
}

size_t	case_redir(char *line)
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '<' || line[i] == '>')
			size++;
		else
			break ;
		i++;
	}
	return (size);
}

static void	flag_up(char c, t_flag *flag, size_t *size)
{
	if (c != ' ')
	{
		flag->flag = 1;
		(*size)++;
	}
	return ;
}

size_t	get_arg_size(char *line)
{
	size_t	size;
	t_flag	flag;
	int		i;

	init_flag(&flag, &i);
	if (line[i] == '<' || line[i] == '>')
		return (case_redir(&line[i]));
	while (line[i])
	{
		if (line[i] == D_QUOTE || line[i] == S_QUOTE)
			handle_quote_flag(&flag, line[i]);
		if (!flag.flag)
			flag_up(line[i], &flag, &size);
		else
		{
			if (line[i] == ' ' && !flag.in_quote)
				break ;
			if ((line[i] == D_QUOTE || line[i] == S_QUOTE) && !flag.in_quote)
				break ;
			size++;
		}
		i++;
	}
	return (size);
}

char	*malloc_tmp_arg(char *line, int *idx)
{
	char	*ret;
	size_t	size;
	size_t	i;

	size = get_arg_size(&line[*idx]);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = line[*idx + i];
		i++;
	}
	ret[i] = 0;
	*idx += size;
	return (ret);
}

char	**malloc_tmp(char *line, size_t size)
{
	char	**ret;
	int		line_idx;
	int		ret_idx;

	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	line_idx = 0;
	ret_idx = 0;
	while (line[line_idx])
	{
		if (line[line_idx] == ' ')
			line_idx++;
		else
		{
			ret[ret_idx] = malloc_tmp_arg(line, &line_idx);
			if (!ret[ret_idx])
				return (ft_free_tmp(ret, ret_idx));
		}
		ret_idx++;
	}
	ret[ret_idx] = NULL;
	return (ret);
}

char	is_closed_quote(char *src, char quote)
{
	size_t	i;

	i = 1;
	while (src[i] && src[i] != quote)
		i++;
	if (src[i] == quote)
		return (quote);
	return (0);
}

size_t	cnt_s_quote(char *src, size_t *size)
{
	size_t	i;

	i = 1;
	while (src[i] && src[i] != S_QUOTE)
	{
		i++;
		(*size)++;
	}
	return (i);
}

size_t	get_env_key_size(char *src)
{
	size_t	i;
	int		ret;

	ret = ft_isdigit(src[1]);
	if (ret)
		return (1);
	i = 1;
	while (src[i])
	{
		ret = ft_isalnum(src[i]);
		if (!(ret || src[i] == '_'))
			return (i - 1);
		i++;
	}
	return (i - 1);
}

size_t	get_env_value_size(char *src, size_t size, char **env_dup)
{
	size_t	i;
	int		ret;

	i = 0;
	while (env_dup[i])
	{
		ret = ft_strncmp(&src[1], env_dup[i], size);
		if (!ret && env_dup[i][size] == '=')
			return (ft_strlen(env_dup[i] + size + 1));
		i++;
	}
	return (0);
}

size_t	cnt_env(char *src, size_t *size, char **env_dup)
{
	size_t	i;
	char	*status;

	i = 0;
	if (src[1] == '?')
	{
		status = ft_itoa(g_exit_status);
		*size += ft_strlen(status);
		free(status);
		return (1);
	}
	if (!src[1] || src[1] == D_QUOTE)
	{
		(*size)++;
		return (0);
	}
	i = get_env_key_size(src);
	*size += get_env_value_size(src, i, env_dup);
	return (i);
}

size_t	get_cmd_arg_size_first(char *src, char **env_dup)
{
	size_t	size;
	size_t	i;
	char	q_close;

	size = 0;
	i = 0;
	while (src[i])
	{
		q_close = 0;
		if (src[i] == D_QUOTE || src[i] == S_QUOTE)
			q_close = is_closed_quote(src + i, src[i]);
		if (src[i] == D_QUOTE && q_close == D_QUOTE)
			i += cnt_d_quote(src + i, &size, env_dup); //
		else if (src[i] == S_QUOTE && q_close == S_QUOTE)
			i += cnt_s_quote(src + i, &size);
		else if (src[i] == '$')
			i += cnt_env(src + i, &size, env_dup);
		i++;
	}
	return (size);
}

char	*set_cmd_arg_first(char *src, char **env_dup, size_t size)
{

}

t_cmd	*parse_cmd(char **srcs, char **env_dup)
{
	t_cmd	*new;
	char	*tmp;
	int		i;
	size_t	arg_size;

	new = (t_cmd *)malloc(sizeof(t_cmd));
		return (ft_free_tmp(srcs, ft_tmpsize(srcs)));
	new->redir_flag = 0;
	new->filename = NULL;
	i = 0;
	while (srcs[i])
	{
		arg_size = 0;
		tmp = srcs[i];
		arg_size = get_cmd_arg_size_first(tmp, env_dup); //
		if (tmp[0] == '<' || tmp[0] == '>')
			handle_redir(); //
		srcs[i] = set_cmd_arg_first(tmp, env_dup, arg_size); //
		free(tmp);
		i++;
	}
	new->cmd_args = srcs;
	return (new);
}

t_cmd	*split_line(char *line, char **env_dup)
{
	t_cmd	*new;
	char	**tmp;
	int		i;
	size_t	size;

	i = 0;
	size = get_split_size(line);
	tmp = malloc_tmp(line, size);
	if (!tmp)
		return (NULL); // error handle
	new = parse_cmd(tmp, env_dup);
	if (!new)
		return (NULL); //
	return (new);
}

t_cmd	*ft_cmdnew(char *line, char **env_dup, int exit_flag, int pipe_flag)
{
	t_cmd	*new;

	if (!line)
		return (NULL);
	new = split_line(line, env_dup);
	new->pipe_flag = pipe_flag;
	if (!exit_flag && !pipe_flag)
		new->exit_flag = 1;
	else
		new->exit_flag = 0;
	new->err.code = 0;
	new->err.err_idx = 0;
	new->err.err_token = NULL;
	new->next = NULL;
	return (new);
}
