/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:30:21 by jseol             #+#    #+#             */
/*   Updated: 2021/07/14 15:28:48 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_size(t_info *info)
{
	double	tmp;

	tmp = listlast(info->a)->num;
	if (tmp > 2147483647 || tmp < -2147483648)
	{
		write(2, "Error\n", 6);
		free_stack(info);
		free(info);
		exit(1);
	}
}

double	push_swap_atoi(const char *str)
{
	int		i;
	int		sign;
	double	ret;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '0')
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '0')
		i++;
	ret = 0;
	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		ret *= 10;
		ret += (str[i++] - '0') * sign;
	}
	return (ret);
}

void	put_stack_a(t_info *info)
{
	int		i;
	char	**ptr;

	i = 0;
	if (info->argc == 2 && info->argv[1][1])
	{
		ptr = ft_split(*(info->argv + 1), ' ');
		while (*(ptr + i))
		{
			stack_add_end(info, 'a', push_swap_atoi(*(ptr + i)));
			check_size(info);
			i++;
		}
		split_free(ptr);
	}
	else
	{
		while (i + 1 < info->argc)
		{
			stack_add_end(info, 'a', push_swap_atoi(*(info->argv + i + 1)));
			check_size(info);
			i++;
		}
	}
	check_duplicate(info);
}
