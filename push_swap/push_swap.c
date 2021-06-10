/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:22:36 by jseol             #+#    #+#             */
/*   Updated: 2021/06/10 16:24:14 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(int argc, char **argv)
{
	t_info	*info;

	info = NULL;
	info = make_info(info);
	put_stack_a(info, argc, argv);
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