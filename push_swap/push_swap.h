/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:53:29 by jseol             #+#    #+#             */
/*   Updated: 2021/07/14 02:36:40 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	double			num;
	char			*operation;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_info
{
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_stack	*operation;
	int				argc;
	char			**argv;
	int				a_size;
	int				*arr;
	int				arr_size;
	int				ra_count;
	int				rb_count;
	int				pa_count;
	int				pb_count;
	int				max;
	int				min;
}					t_info;

void				push_swap(int argc, char **argv);
int					check_num(int argc, char **argv);
int					check_num_1(char **ptr);
int					check_num_2(char **argv);
t_info				*make_info(t_info *info, int argc, char **argv);
void				put_stack_a(t_info *info);
double				push_swap_atoi(const char *str);
void				check_size(t_info *info);
void				check_duplicate(t_info *info);
void				stack_add_top(t_info *info, char stack_name, double num);
void				stack_add_top_2(t_info *info, t_stack **top, double num);
void				stack_add_end(t_info *info, char stack_name, double num);
void				stack_add_end_1(t_info *info, t_stack **top, double num);
void				stack_add_end_2(t_info *info, t_stack **top, double num);
void				stack_del_top(t_info *info, char stack_name);
void				stack_del_end(t_info *info, char stack_name);
void				sa(t_info *info);
void				sb(t_info *info);
void				ss(t_info *info);
void				pa(t_info *info);
void				pb(t_info *info);
void				ra(t_info *info);
void				rb(t_info *info);
void				rr(t_info *info);
void				rra(t_info *info);
void				rrb(t_info *info);
void				rrr(t_info *info);
t_stack				*listlast(t_stack *lst);
t_stack				*listfirst(t_stack *lst);
int					listcount(t_stack *top);
void				sort_a(t_info *info);
void				hardsorting_a(t_info *info, t_stack *top, t_stack *end);
void				hardsorting_b(t_info *info, t_stack *top, t_stack *end);
void				hardsorting_2(t_info *info, t_stack *stack, int size);
void				hardsorting_2_a(t_info *info, int a, int b, int c);
void				hardsorting_2_b(t_info *info, int a, int b, int c);
void				case_1(t_info *info, int flag);
void				case_2(t_info *info, int flag);
void				sort_3(t_info *info, t_stack *stack);
void				sort_5(t_info *info);
void				sort_5_1(t_info *info);
void				sort_5_2(t_info *info);
void				sort_5_3(t_info *info);
void				sort_remain(t_info *info, t_stack *stack, int size);
void				get_array(t_info *info, t_stack *stack, int size);
void				sort_array(t_info *info, int size);
void				a_to_b(t_info *info, int size);
void				b_to_a(t_info *info, int size);
void				a_to_b_2(t_info *info, int pivot, int size);
void				b_to_a_2(t_info *info, int pivot, int size);
int					rb_count(t_stack *tmp, t_stack *tmp_last);
int					rrb_count(t_stack *tmp, t_stack *tmp_last);
void				check_sorted(t_info *info);
void				sort_arr(int *arr, int count);
void				split_free(char **ptr);
void				free_b(t_info *info);
void				free_stack(t_info *info);
t_stack				*create_node(char *operation);
void				append_node(t_stack **head, t_stack *newnode);
void				compress_oper(t_stack *oper);
int					compression_condition(t_stack *oper);

#endif
