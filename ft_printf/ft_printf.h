/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:59:37 by jseol             #+#    #+#             */
/*   Updated: 2021/05/20 16:22:47 by jseol            ###   ########.fr       */
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

void				setf(t_format *f);
void				checkoption(char *format, int i, t_format *f, va_list ap);
int					checkprint(t_format *f, va_list ap);
int					get_format(va_list ap, char *format, t_format *f);
int					ft_printf(const char *format, ...);



#endif
