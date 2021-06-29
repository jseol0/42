/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:39:39 by jseol             #+#    #+#             */
/*   Updated: 2021/06/29 19:39:48 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_remain_down(t_info *info, int count)
{
	t_stack	*tmp;
	int		index;
	int		i;

	index = listcount(info->a) - 1;
	tmp = info->a;
	tmp = listlast(tmp);
	while (tmp)
	{
		i = 0 + (info->chunk_count * count);
		while (i < info->remain_chunk + (info->chunk_count * count))
		{
			if (tmp->num == info->chunk[i])
				return (index);
			i++;
		}
		tmp = tmp->prev;
		index--;
	}
	return (index);
}

int			find_remain_top(t_info *info, int count)
{
	t_stack	*tmp;
	int		index;
	int		i;

	index = 0;
	tmp = info->a;
	while (tmp)
	{
		i = 0 + (info->chunk_count * count);
		while (i < info->remain_chunk + (info->chunk_count * count))
		{
			if (tmp->num == info->chunk[i])
				return (index);
			i++;
		}
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int			find_chunk_down(t_info *info)
{
	t_stack	*tmp;
	int		index;
	int		i;

	index = listcount(info->a) - 1;	//info->a_size;
	tmp = info->a;
	tmp = listlast(tmp);
	while (tmp)
	{
		i = 0;
		while (i < info->first_a_size)
		{
			if (tmp->num == info->chunk[i])
				return (index);
			i++;
		}
		tmp = tmp->prev;
		index--;
	}
	return (0);
}

int			find_chunk_top(t_info *info)
{
	t_stack	*tmp;
	int		index;
	int		i;

	index = 0;
	tmp = info->a;
	while (tmp)
	{
		i = 0;
		while (i < info->first_a_size)
		{
			if (tmp->num == info->chunk[i])
				return (index);
			i++;
		}
		tmp = tmp->next;
		index++;
	}
	return (index);
}

void	a_to_b(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->a_size)
	{
		push_b(info);
		i++;
	}
}

void	sort_a(t_info *info, int a_size)
{
	if (a_size <= 5)
		sort_remain(info, a_size);
	else
	{
		get_chunk(info);
		a_to_b(info);
		while (info->b)
			pa(info);
		free(info->chunk);
	}
}
