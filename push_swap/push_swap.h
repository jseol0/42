/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:53:29 by jseol             #+#    #+#             */
/*   Updated: 2021/06/28 17:15:30 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stack
{
	long			num;
	char			*operation;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_info
{
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_stack	*operation;
	int				argc;
	char			**argv;
	int				a_size;
	int				chunk_size;
	int				remain_chunk;
	int				max;
	int				min;
	int				*chunk;
	int				b_max;
	int				b_min;
	int				a_move;
	int				b_move;
	int				a_move_count;
	int				b_move_count;
	int				a_num_prev;
	int				a_num_next;
	int				b_after_move;
}					t_info;

void				push_swap(int argc, char **argv);
int					check_error(int argc, char **argv);
t_info				*make_info(t_info *info, int argc, char **argv);
void				put_stack_a(t_info *info);
long				push_swap_atoi(const char *str);
void				check_size(t_info *info);
void				check_duplicate(t_info *info);
void				stack_add_top(t_info *info, char stack_name, long num);
void				stack_del_top(t_info *info, char stack_name);
void				stack_add_end(t_info *info, char stack_name, long num);
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
void				sort_a(t_info *info, int a_size);
void				hardsorting(t_info *info, t_stack *top, t_stack *end);
void				sort_3(t_info *info);
void				sort_remain(t_info *info, int size);
void				get_chunk(t_info *info);
void				get_chunk_size(t_info *info, int a_size);
void				sort_chunk(t_info *info);
int					find_chunk_top(t_info *info, int count);
int					find_chunk_down(t_info *info, int count);
int					find_remain_top(t_info *info, int count);
int					find_remain_down(t_info *info, int count);
void				a_to_b(t_info *info);
void				push_b_first(t_info *info, int top, int down);
void				push_b(t_info *info, int top, int down, int count, int i);
void				move_stack(t_info *info);
void				move_stack_0(t_info *info);
void				move_stack_1(t_info *info);
void				move_stack_2(t_info *info);
void				move_stack_3(t_info *info);
void				b_after_move(t_info *info);
void				move_check(t_info *info, int top, int down);
void				move_b_check_1(t_info *info);
void				move_b_check_2(t_info *info);
void				move_b_check_3(t_info *info);
void				move_b_check_4(t_info *info, int a_num);
void				move_b_check_5(t_info *info, t_stack *tmp_b,
									t_stack *tmp_b_last);
int					rb_count(t_stack *tmp, t_stack *tmp_last);
int					rrb_count(t_stack *tmp, t_stack *tmp_last);
void				find_b_in_chunk_1(t_info *info, int a_num);
void				find_b_in_chunk_2(t_info *info, int a_num);
void				check_sorted(t_info *info);
void				sort_arr(int *arr, int count);
void				split_free(char **ptr);
void				free_b(t_info *info);
void				free_stack(t_info *info);
t_stack 			*create_node(char *operation);
void				append_node(t_stack **head, t_stack *newnode);
void				compress_oper(t_stack *oper);
int					compression_condition(t_stack *oper);

#endif
