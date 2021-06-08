/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:53:29 by jseol             #+#    #+#             */
/*   Updated: 2021/06/08 23:30:33 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int				num;
	struct s_list	*next;

}				t_list;

typedef struct	s_info
{
	struct s_list *a;
	struct s_list *b;
}				t_info;



#endif
