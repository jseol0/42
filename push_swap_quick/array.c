/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:24:33 by jseol             #+#    #+#             */
/*   Updated: 2021/06/30 14:43:09 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(t_info *info, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (info->arr[j] > info->arr[j + 1])
			{
				tmp = info->arr[j];
				info->arr[j] = info->arr[j + 1];
				info->arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void		get_array(t_info *info, t_stack *stack, int size)	//free
{
	t_stack	*tmp;
	int		i;

	if (!(info->arr = (int *)malloc(sizeof(int) * size)))
	{
		free_stack(info);
		free(info);
		exit(1);
	}
	tmp = stack;
	i = 0;
	while (i < size)
	{
		info->arr[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	sort_array(info, size);
}
