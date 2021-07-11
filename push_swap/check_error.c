/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:55:57 by jseol             #+#    #+#             */
/*   Updated: 2021/07/11 16:23:31 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sorted(t_info *info)
{
	int		i;
	t_stack	*tmp_a;

	tmp_a = info->a;
	i = 0;
	while (tmp_a)
	{
		if (tmp_a->num != info->arr[i++])
		{
			free(info->arr);
			return ;
		}
		tmp_a = tmp_a->next;
	}
	free_stack(info);
	free(info->arr);
	free(info);
	exit(0);
}

void	check_size(t_info *info)
{
	long	tmp;

	tmp = info->a->num;
	if (tmp > 2147483647 || tmp < -2147483648)
	{
		write(2, "Error\n", 6);
		free_stack(info);
		free(info);
		exit(1);
	}
}

void	check_duplicate(t_info *info)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = info->a;
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL)
		{
			if (tmp1->num == tmp2->num)
			{
				write (2, "Error\n", 6);
				free_stack(info);
				free(info);
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	check_error(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		exit(1);
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
