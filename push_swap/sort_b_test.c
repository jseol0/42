#include "push_swap.h"

void	sort_b(t_info *info, int b_size)
{
	printf("              %ld\n", info->b->num);

	int	i;
	int	rb_count;
	int	pa_count;
	int	ra_count;

	i = 0;
	if (b_size < 3)
	{
		sort_remain(info, 'b', b_size);
		while (i++ < b_size)
			pa(info);
		return ;
	}
	get_middle_num(info, 'b');
	get_pivot_s(info, 'b');
	get_pivot_l(info, 'b');

	rb_count = 0;
	pa_count = 0;
	ra_count = 0;
	while (i++ < b_size)
	{
		if (info->b->num <= info->pivot_s)
		{
			rb(info);
			rb_count++;
		}
		else
		{
			pa(info);
			pa_count++;
			if (info->a->num >= info->pivot_l)
			{
				ra(info);
				ra_count++;
			}
		}
	}
	sort_a(info, pa_count - ra_count);
	rerocate(info, ra_count, rb_count);
	sort_a(info, rb_count);
	sort_b(info, ra_count);
}
