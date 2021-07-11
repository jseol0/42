/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:25:04 by jseol             #+#    #+#             */
/*   Updated: 2021/07/11 16:43:40 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*make_info(t_info *info, int argc, char **argv)
{
	info = (t_info *)malloc(sizeof(t_info));
	if (info == NULL)
		exit(1);
	info->a = NULL;
	info->b = NULL;
	info->operation = NULL;
	info->argc = argc;
	info->argv = argv;
	info->a_size = 0;
	info->a_size = 0;
	info->max = 0;
	info->min = 0;
	info->ra_count = 0;
	info->pb_count = 0;
	info->rb_count = 0;
	info->pa_count = 0;
	return (info);
}
