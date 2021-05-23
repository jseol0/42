/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:59:37 by jseol             #+#    #+#             */
/*   Updated: 2021/05/23 19:48:45 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define TYPE "cspdiuxX%"
# define UPBASE "0123456789ABCDEF"
# define BASE "0123456789abcdef"

typedef struct		s_format
{
	int				zero;
	int				neg;
	int				width;
	int				prec;
	char			spec;
}					t_format;

/*
	ft_printf
*/
void				checkoption(char *format, int i, t_format *f, va_list ap);
int					checkprint(t_format *f, va_list ap);
int					get_format(va_list ap, char *format, t_format *f);
int					ft_printf(const char *format, ...);

/*
	check
*/
int					get_size(t_format *f, char *s);
int					print_str(t_format *f, char *s);
int					print_nbr(t_format *f, unsigned long long num);

/*
	utils
*/
void				setf(t_format *f);
int					ft_putchar(char c);
int					ft_putstr(char *s);
char				*putret(char *buf);
char				*ft_itoa(int n, t_format *f);
char				*ft_utoa(unsigned int n, t_format *f);



#endif
