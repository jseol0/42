/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:09:26 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/30 23:27:14 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int	philo;
	int	die;
	int	eat;
	int	sleep;
	int	must_eat;
}	t_philo;

/*
main
*/
int		main(int argc, char **argv);
void	init_philo(int	argc, char ** argv, t_philo *p);
int		ft_error(char *s);

/*
utils
*/
void	ft_putstr_fd(char *s, int fd);
int		ft_is_digit(char c);
int		check_numeric(char **argv);
int		ft_atoi(char *s);

#endif