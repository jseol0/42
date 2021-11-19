/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:01:28 by jseol             #+#    #+#             */
/*   Updated: 2021/11/19 18:09:40 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		printf("infile: %s\n", tmp.infile);
		printf("outfile: %s\n", tmp.outfile);
		printf("cmd1: %s\n", tmp.cmd[0].cmd[0]);
		printf("cmd2: %s\n", tmp.cmd[1].cmd[0]);
		printf("path1: %s\n", tmp.cmd[0].path);
		printf("path2: %s\n", tmp.cmd[1].path);
	}
	else
		ft_error("Wrong command count");
	return (0);
}

/*
	ft_free()
	만들기
	pipex() 함수 구상

	****free()*****
	tmp->infile
	tmp->outfile
	tmp->path
	tmp->cmd->cmd
	tmp->cmd->path
*/
