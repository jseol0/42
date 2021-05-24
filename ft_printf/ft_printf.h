/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:59:37 by jseol             #+#    #+#             */
/*   Updated: 2021/05/24 23:25:44 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

# define TYPE "cspdiuxX%"
# define UPBASE "0123456789ABCDEF"
# define BASE "0123456789abcdef"

typedef struct		s_format
{
	int				zero;
	int				minus;
	int				width;
	int				prec;
	char			spec;
}					t_format;

/*
**	ft_printf
*/
void				checkoption(const char *format, int i, t_format *f, va_list *ap);
int					checkprint(t_format *f, va_list *ap);
int					get_format(va_list *ap, const char *format, t_format *f);
int					ft_printf(const char *format, ...);

/*
**	check
*/
int					applyformat(t_format *f, char *dst, char *src);
int					get_size(t_format *f, char *s);
int					print_char(t_format *f, char c);
int					print_str(t_format *f, char *s);
int					print_nbr(t_format *f, unsigned long long num);

/*
**	nbr
*/
char				*putret(char *buf);
char				*ft_itoa(int n);
char				*ft_utoa(unsigned int n);
char				*ft_hextoa(unsigned long long n, t_format *f);

/*
**	utils
*/
int					ft_strlen(char *s);
void				setf(t_format *f);
int					ft_putchar(char c);
int					ft_putstr(char *s);
int					ft_strchr(const char *s, int c);
char				*ft_strncpy(char *s1, char *s2, int n);

#endif
