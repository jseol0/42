/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:01:28 by jseol             #+#    #+#             */
/*   Updated: 2021/11/16 23:47:46 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* parse_input_value */
void	check_slash(t_cmd *cmd, const char *tmp)
{
	if (ft_strncmp(tmp, "/", 1) == 0
		|| ft_strncmp(tmp, "./", 2) == 0 || ft_strncmp(tmp, "../", 3) == 0)
		cmd->slash = TRUE;
	else
		cmd->slash = FALSE;
}

char	*find_path(char **envp)
{
	int	i;
	char	*ret;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			ret = ft_strdup(envp[i] + 5);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

void	parse_input_value(t_tmp *tmp, char **argv, char **envp)
{
	char	*tmp_path;

	tmp->infile = ft_strdup(argv[1]);
	tmp->cmd[0].cmd = ft_split(argv[2], ' ');	//	'ls -l', 'wc -l' 옵션 나누기
	check_slash(&tmp->cmd[0], argv[2]);	//	./, ../, /
	tmp->cmd[1].cmd = ft_split(argv[3], ' ');
	check_slash(&tmp->cmd[1], argv[3]);
	tmp->outfile = ft_strdup(argv[4]);
	tmp_path = find_path(envp);			//	환경변수중에 PATH 만 가져오기
	tmp->path = ft_split(tmp_path, ':');
	free(tmp_path);
}


/* check_parsing */
//set_cmd	만들기

void check_command(t_tmp *tmp)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (tmp->cmd[i].slash == FALSE)
		{
			if (set_cmd(tmp, &tmp->cmd[i]) == FALSE)
			{
				ft_free(tmp);
				ft_error("Command not found");
			}
		}
		else
			tmp->cmd[i].path = ft_strdup(tmp->cmd[i].cmd[0]);
		i++;
	}
}

void	check_parsing(t_tmp *tmp)
{
	tmp->infile_fd = open(tmp->infile, O_RDWR);
	if (tmp->infile_fd < 0)
	{
		ft_free(tmp);
		ft_error("Not valid infile");
	}
	tmp->outfile_fd = open(tmp->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (tmp->outfile_fd < 0)
	{
		ft_free(tmp);
		ft_error("Not valid outfile");
	}
	if (tmp->path == NULL && (tmp->cmd[0].slash == FALSE || tmp->cmd[1].slash == FALSE))
	{
		ft_free(tmp);
		ft_error("Wrong path");
	}
	check_command(tmp);
}


/* main */
int	main(int argc, char **argv, char **envp)
{
	t_tmp	tmp;

	if (argc == 5)
	{
		ft_memset(&tmp, 0, sizeof(t_tmp));
		//파싱함수
		parse_input_value(&tmp, argv, envp);
		//파싱체크함수
		check_parsing(&tmp);
		//pipex 주요기능 작동함수(pipe, fork, execve...)
	}
	else
		ft_error("Wrong command count");
	return (0);
}

/*

	ft_free()
	set_cmd()
	만들기
	pipex() 함수 구상
*/
