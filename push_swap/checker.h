/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:27:32 by jseol             #+#    #+#             */
/*   Updated: 2021/07/13 17:54:50 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./get_next_line/get_next_line.h"
# include "push_swap.h"

void	checker(t_info *info);
int		check_oper(t_info *info, char *line);
int		check_oper_1(t_info *info, char *line);
int		ft_is_sorted(t_info *info);

#endif
