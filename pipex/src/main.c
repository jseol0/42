/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:01:28 by jseol             #+#    #+#             */
/*   Updated: 2021/11/24 15:28:09 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *s)
{
	perror(s);
	exit(1);
}

void	ft_free(t_tmp *tmp)
{
	int	i;

	if (tmp->infile != NULL)
		free(tmp->infile);
	if (tmp->outfile != NULL)
		free(tmp->outfile);
	i = 0;
	while (i < 2)
	{
		if (tmp->cmd[i].cmd != NULL)
			free(tmp->cmd[i].cmd);
		if (tmp->cmd[i].path != NULL)
			free(tmp->cmd[i].path);
		i++;
	}
	i = 0;
	if (tmp->path != NULL)
	{
		while (tmp->path[i] != NULL)
		{
			free(tmp->path[i]);
			i++;
		}
		free(tmp->path);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_tmp	tmp;
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		ft_memset(&tmp, 0, sizeof(t_tmp));
		parse_input_value(&tmp, argv, envp);
		check_parsing(&tmp);
		if ((pipe(fd)) == ERROR)
		{
			ft_free(&tmp);
			ft_error("pipe");
		}
		pid = fork();
		pipex(&tmp, fd, envp, pid);
	}
	else
		ft_error("Wrong command count");
	return (0);
}
