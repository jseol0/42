/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:22:36 by jseol             #+#    #+#             */
/*   Updated: 2021/07/14 23:02:54 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_info	*info;
	t_stack	*tmp;

	info = NULL;
	info = make_info(info, argc, argv);
	put_stack_a(info);
	info->a_size = listcount(info->a);
	get_array(info, info->a, info->a_size);
	check_sorted(info);
	sort_a(info);
	compress_oper(info->operation);
	tmp = info->operation;
	while (tmp)
	{
		ft_putstr_fd(tmp->operation, 1);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	free_stack(info);
	free(info);
}

int	main(int argc, char **argv)
{
	if (check_num(argc, argv))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	push_swap(argc, argv);
	return (0);
}
