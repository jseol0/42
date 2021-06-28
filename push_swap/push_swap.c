/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:22:36 by jseol             #+#    #+#             */
/*   Updated: 2021/06/28 17:43:06 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(int argc, char **argv)
{
	t_info	*info;
	int a_size;

	info = NULL;
	info = make_info(info, argc, argv);
	put_stack_a(info);
	a_size = listcount(info->a);
	info->a_size = a_size;
	check_sorted(info);
	sort_a(info, a_size);
	compress_oper(info->operation);
	while (info->operation)
	{
		printf("%s\n", info->operation->operation);
		info->operation = info->operation->next;
	}
	free_stack(info);
	free(info);
}

int	main(int argc, char **argv)
{
	if (check_error(argc, argv))
	{
		write (2, "Error\n", 6);
		return (-1);
	}
	push_swap(argc, argv);
	return (0);
}
