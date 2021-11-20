/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:01:28 by jseol             #+#    #+#             */
/*   Updated: 2021/11/20 17:39:49 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_tmp	tmp;
	int	fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		ft_memset(&tmp, 0, sizeof(t_tmp));
		//파싱함수
		parse_input_value(&tmp, argv, envp);
		//파싱체크함수
		check_parsing(&tmp);
		//pipex 주요기능 작동함수(pipe, fork, execve...)
		if ((pipe(fd)) == -1)
		{
			//ft_free(tmp);
			ft_error("pipe");
		}
		pid = fork();
		pipex(&tmp, fd, envp, pid);
	}
	else
		ft_error("Wrong command count");
	return (0);
}

/*
	ft_free()
	만들기

	****free()*****
	tmp->infile
	tmp->outfile
	tmp->path
	tmp->cmd->cmd
	tmp->cmd->path		-check_parsing
*/
