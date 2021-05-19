/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:59:37 by jseol             #+#    #+#             */
/*   Updated: 2021/05/19 21:08:10 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define TYPE "cspdiuxX%"

typedef struct		s_format
{
	int				zero;
	int				neg;
	int				widht;
	int				prec;
	char			spec;
}					t_format;

int			ft_printf(const char *format, ...);

#endif
