/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:59:37 by jseol             #+#    #+#             */
/*   Updated: 2021/05/26 23:36:32 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define ERROR -1
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
	int				num_sign;
}					t_format;

/*
**	ft_printf
*/
void		check_width_and_prec(va_list *ap, const char *format, t_format *f, int i);
void		checkoption(const char *format, int i, t_format *f, va_list *ap);
int			checkprint(t_format *f, va_list *ap);
int			get_format(va_list *ap, const char *format, t_format *f);
int			ft_printf(const char *format, ...);

/*
**	check
*/
int			get_size(t_format *f, char *s);
int			print_char(t_format *f, char c);
int			print_str(t_format *f, char *s);
int			print_nbr(t_format *f, unsigned long long num);
int			put_width_char(int width, int len, int zero);
int			put_width_str(char **buf, t_format *f);

/*
**	nbr
*/
char		*putret(char *buf);
char		*ft_itoa(int n);
char		*ft_utoa(unsigned int n);
char		*ft_hextoa(unsigned long long n, t_format *f);
int			put_pointer(char **buf);
int			put_minus(t_format *f, char **buf);
char		*put_prec_nbr(char *tmp, t_format *f, int buf_len);
int			put_minus_2(int buf_len, t_format *f, char **buf);

/*
**	utils
*/
int			ft_strlen(char *s);
void		setf(t_format *f);
int			ft_putchar(char c);
void		ft_putstr(char *s);
int			ft_strchr(const char *s, int c);
int			ft_isdigit(int c);
char		*ft_strjoin(char *s1, char *s2);

#endif
