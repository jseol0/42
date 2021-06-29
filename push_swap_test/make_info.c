/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:25:04 by jseol             #+#    #+#             */
/*   Updated: 2021/06/29 16:00:01 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*make_info(t_info *info, int argc, char **argv)
{
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		exit(1);
	info->a = NULL;
	info->b = NULL;
	info->operation = NULL;
	info->argc = argc;
	info->argv = argv;
	info->a_size = 0;
	info->first_a_size = 0;
	info->max = 0;
	info->min = 0;
	info->chunk_size = 0;
	info->chunk_count = 20;
	info->remain_chunk = 0;
	info->b_max = -2147483648;
	info->b_min = 2147483647;
	info->a_move = 0;
	info->b_move = 0;
	info->a_move_count = 0;
	info->b_move_count = 0;
	info->a_num_prev = 0;
	info->a_num_next = 0;
	info->b_after_move = 0;
	return (info);
}
