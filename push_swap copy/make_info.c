/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:25:04 by jseol             #+#    #+#             */
/*   Updated: 2021/06/17 15:35:16 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*make_info(t_info *info, int argc, char **argv)
{
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		exit (1);
	info->a = NULL;
	info->b = NULL;
	info->argc = argc;
	info->argv = argv;
	info->middle = 0;
	info->middle_s = 0;
	info->middle_l = 0;
	info->pivot = 0;
	info->pivot_s = 0;
	info->pivot_l = 0;
	info->a_size = 0;
	info->max = 0;
	info->min = 0;

	return (info);
}
