#include "push_swap.h"

void	get_middle_num(t_info *info, char stack_name)
{
	int max;
	int min;
	t_stack *tmp;

	if (stack_name == 'a')
		tmp = info->a;
	else
		tmp = info->b;
	max = tmp->num;
	min = tmp->num;
	while (tmp)
	{
		max = max < tmp->num ? tmp->num : max;
		min = min > tmp->num ? tmp->num : min;
		tmp = tmp->next;
	}
	info->middle_s = (max + min) / 3;
	info->middle_l = ((max + min) / 3) * 2;
}

void	get_pivot_s(t_info *info, char stack_name)
{
	int pivot;
	int mid_num;
	t_stack *tmp;

	if (stack_name == 'a')
		tmp = info->a;
	else
		tmp = info->b;
	pivot = tmp->num;
	while (tmp)
	{
		mid_num = info->middle_s - tmp->num;
		pivot = ft_abs(info->middle_s - pivot) > ft_abs(mid_num) ? tmp->num : pivot;
		tmp = tmp->next;
	}
	info->pivot_s = pivot;
}

void	get_pivot_l(t_info *info, char stack_name)
{
	int pivot;
	int mid_num;
	t_stack *tmp;

	if (stack_name == 'a')
		tmp = info->a;
	else
		tmp = info->b;
	pivot = tmp->num;
	while (tmp)
	{
		mid_num = info->middle_l - tmp->num;
		pivot = ft_abs(info->middle_l - pivot) > ft_abs(mid_num) ? tmp->num : pivot;
		tmp = tmp->next;
	}
	info->pivot_l = pivot;
}

void	rerocate(t_info *info, int ra_count, int rb_count)
{
	int	count;
	int	i;

	count = ra_count < rb_count ? ra_count : rb_count;
	i = 0;
	while (i < count)
	{
		rrr(info);
		i++;
	}
	i = 0;
	if (ra_count > rb_count)
	{
		while (i++ < ra_count - rb_count)
			rra(info);
	}
	else
	{
		while (i++ < rb_count - ra_count)
			rrb(info);
	}
}

void	sort_a(t_info *info, int a_size)
{
	if (a_size < 3)
	{
		printf("                       4\n");
		sort_remain(info, 'a', a_size);
		printf("                       5\n");
		return ;
	}
	int	i;
	int	ra_count;
	int	pb_count;
	int	rb_count;

	get_middle_num(info, 'a');
	get_pivot_s(info, 'a');
	get_pivot_l(info, 'a');
	printf("%d %d\n", info->pivot_s, info->pivot_l);

	ra_count = 0;
	pb_count = 0;
	rb_count = 0;
	i = 0;
	while (i++ < a_size)
	{
		if (info->a->num >= info->pivot_l)
		{
			ra(info);
			ra_count++;
		}
		else
		{
			pb(info);
			pb_count++;
			if (info->b->num >= info->pivot_s)
			{
				rb(info);
				rb_count++;
			}
		}
	}
	rerocate(info, ra_count, rb_count);
	printf("                       0\n");
	sort_a(info, ra_count);
	printf("                       1\n");
	sort_b(info, rb_count);
	printf("                       2\n");
	sort_b(info, pb_count - rb_count);
}
