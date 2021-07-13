/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:55:57 by jseol             #+#    #+#             */
/*   Updated: 2021/07/14 02:36:58 by jseol            ###   ########.fr       */
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

int	check_num_2(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || argv[i][j] == ' ')
				j++;
			else if (argv[i][j] == '+' && ft_isdigit(argv[i][j + 1]))
				j++;
			else if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_num_1(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ft_isdigit(ptr[i][j]) || ptr[i][j] == ' ')
				j++;
			else if (ptr[i][j] == '+' && ft_isdigit(ptr[i][j + 1]))
				j++;
			else if (ptr[i][j] == '-' && ft_isdigit(ptr[i][j + 1]))
				j++;
			else
			{
				split_free(ptr);
				return (1);
			}
		}
		i++;
	}
	split_free(ptr);
	return (0);
}

int	check_num(int argc, char **argv)
{
	char	**ptr;

	if (argc < 2)
		exit(1);
	if (argc == 2)
	{
		ptr = ft_split(*(argv + 1), ' ');
		return (check_num_1(ptr));
	}
	else if (argc > 2)
	{
		return (check_num_2(argv));
	}
	return (0);
}
