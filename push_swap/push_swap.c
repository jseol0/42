/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:22:36 by jseol             #+#    #+#             */
/*   Updated: 2021/07/11 02:04:37 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(int argc, char **argv)
{
	t_info	*info;

	info = NULL;
	info = make_info(info, argc, argv);
	put_stack_a(info);
	info->a_size = listcount(info->a);
	get_array(info, info->a, info->a_size);
	check_sorted(info);
	sort_a(info);
	compress_oper(info->operation);
	while (info->operation)
	{
		ft_putstr_fd(info->operation->operation, 1);
		write(1, "\n", 1);
		info->operation = info->operation->next;
	}
	// t_stack *tmp = info->a;
	// while (tmp)
	// {
	// 	printf("%ld ", tmp->num);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	free_stack(info);
	free(info);
}

int	main(int argc, char **argv)
{
	if (check_error(argc, argv))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	push_swap(argc, argv);
	return (0);
}
