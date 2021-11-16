/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:28:26 by jseol             #+#    #+#             */
/*   Updated: 2021/11/16 20:13:58 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#define TRUE 0
#define FALSE 1

typedef struct s_cmd
{
	char		**cmd;
	int			slash;	// TRUE or FALSE
}				t_cmd;
​
typedef struct s_tmp
{
	char		**path;
	char		*infile;
	int			infile_fd;
	char		*outfile;
	int			outfile_fd;
	t_cmd		cmd[2];
}				t_tmp;
​

#endif
