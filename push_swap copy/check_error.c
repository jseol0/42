/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:55:57 by jseol             #+#    #+#             */
/*   Updated: 2021/06/09 17:00:12 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_error(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		return (1);
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) || argv[1][i] == ' ')
			i++;
		else if (argv[1][i] == '+' && ft_isdigit(argv[1][i + 1]))
			i++;
		else if (argv[1][i] == '-' && ft_isdigit(argv[1][i + 1]))
			i++;
		else
			return (1);
	}
	return (0);
}
