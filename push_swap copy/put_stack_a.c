/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:30:21 by jseol             #+#    #+#             */
/*   Updated: 2021/06/15 12:30:43 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long		push_swap_atoi(const char *str)
{
	int		i;
	int		sign;
	long	ret;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	ret = 0;
	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		ret *= 10;
		ret += (str[i] - '0') * sign;
		i++;
	}
	return (ret);
}

void	check_size(t_info *info)
{
	long tmp;

	tmp = info->a->num;
	if (tmp > 2147283647 || tmp < -2147483648)
	{
		write (2, "error\n", 6);
		exit (1);
	}
}

void	check_duplicate(t_info *info)
{
	t_stack *tmp1;
	t_stack *tmp2;

	tmp1 = info->a;
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL)
		{
			if (tmp1->num == tmp2->num)
			{
				write (2, "error\n", 6);
				exit (1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	put_stack_a(t_info *info)
{
	int		i;
	char	**ptr;

	i = 0;
	if (info->argc == 2 && info->argv[1][1])
	{
		ptr = ft_split(*(info->argv + 1), ' ');	// free
		while (*(ptr + i))
		{
			stack_add_end(info, 'a', atoi(*(ptr + i)));
			i++;
			check_size(info);
		}
	}
	else
	{
		while (i + 1 < info->argc)
		{
			stack_add_end(info, 'a', atoi(*(info->argv + i + 1)));
			i++;
			check_size(info);
		}
	}
	info->a_size = i;
	check_duplicate(info);
}
