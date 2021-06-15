/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:22:36 by jseol             #+#    #+#             */
/*   Updated: 2021/06/15 10:53:34 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(int argc, char **argv)
{
	t_info	*info;

	info = NULL;
	info = make_info(info, argc, argv);
	put_stack_a(info);
	sort_a(info);
}

int	main(int argc, char **argv)
{
	if (check_error(argc, argv))
	{
		write (2, "error\n", 6);
		return (-1);
	}
	push_swap(argc, argv);

	return (0);
}
