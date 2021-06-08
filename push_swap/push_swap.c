/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:22:36 by jseol             #+#    #+#             */
/*   Updated: 2021/06/08 17:14:32 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "lihft.h"


int	main(int argc, char **argv)
{
	int		arr[50];
	int		i;
	int		pivot;
	char	**ptr;
/*
	if (check_error)
		write (2, "error\n", 6);
*/
	i = 0;
	if (argc == 2 && argv[1][1])
	{
		ptr = ft_split(*(argv + 1), ' ');
		while (*(ptr + i))
		{
			arr[i] = atoi(*(ptr + i));
			i++;
		}
	}
	else
	{
		while (i + 1 < argc)
		{
			arr[i] = atoi(*(argv + i + 1));
			i++;
		}
	}
	pivot = i;

	for (int i = 0; i < pivot; i++)
		printf("%d\n", arr[i]);
	return (0);
}
