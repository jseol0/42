/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:01:28 by jseol             #+#    #+#             */
/*   Updated: 2021/11/20 18:18:42 by jseol            ###   ########.fr       */
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
		parse_input_value(&tmp, argv, envp);
		check_parsing(&tmp);
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
	tmp->cmd->cmd							-execve()
	tmp->cmd->path		-check_parsing		-execve()
*/
