/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:30:52 by jseol             #+#    #+#             */
/*   Updated: 2021/07/13 18:08:47 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_is_sorted(t_info *info)
{
	int i;
	t_stack	*tmp_a;

	tmp_a = info->a;
	i = 0;
	while (tmp_a)
	{
		if (tmp_a->num != info->arr[i++])
			return (0);
		tmp_a = tmp_a->next;
	}
	return (1);
}

int	check_oper_1(t_info *info, char *line)
{
	if (ft_strstr(line, "rr"))
	{
		if (ft_strstr(line, "rra"))
			rra(info);
		else if (ft_strstr(line, "rrb"))
			rrb(info);
		else if (ft_strstr(line, "rrr"))
			rrr(info);
		else
			rr(info);
	}
	else
		return (0);
	return (1);
}

int	check_oper(t_info *info, char *line)
{
	int i;

	i = 1;
	if (ft_strstr(line, "sa"))
		sa(info);
	else if (ft_strstr(line, "sb"))
		sb(info);
	else if (ft_strstr(line, "ss"))
		ss(info);
	else if (ft_strstr(line, "pa"))
		pa(info);
	else if (ft_strstr(line, "pb"))
		pb(info);
	else if (ft_strstr(line, "ra") && !ft_strstr(line, "rr"))
		ra(info);
	else if (ft_strstr(line, "rb") && !ft_strstr(line, "rr"))
		rb(info);
	else
		i = check_oper_1(info, line);
	return (i);
}

void	checker(t_info *info)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) == 1)
	{
		i = check_oper(info, line);
		if (i == 0)
		{
			write(2, "Error\n", 6);
			free_stack(info);
			free(info);
			exit(0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (check_error(argc, argv))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	info = NULL;
	info = make_info(info, argc, argv);
	put_stack_a(info);
	info->a_size = listcount(info->a);
	get_array(info, info->a, info->a_size);
	checker(info);
	if (ft_is_sorted(info))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_stack(info);
	free(info->arr);
	free(info);
	return (0);
}
