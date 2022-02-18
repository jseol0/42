/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:09:26 by jaeyu             #+#    #+#             */
/*   Updated: 2022/02/11 17:12:30 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_mutex
{
	pthread_mutex_t	m_out;
	pthread_mutex_t	m_data;
	pthread_mutex_t	*fork;
}	t_mutex;

typedef struct s_rule
{
	int				philo_num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
}	t_rule;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				l_fork;
	int				r_fork;
	int				eat_cnt;
	struct s_rule	*rule;
	struct s_mutex	*mutex;
	struct timeval	start_tv;
	struct timeval	life_tv;
}	t_philo;

/*
main
*/
int		is_died(t_philo *phs);
int		is_all_eat(t_philo *phs);
void	*monitor(void *philos);
void	*routine(void *philo);

/*
utils
*/
int		ft_atoi(char *s);
long	get_time(struct timeval start);
int		is_valid_arg(int argc, char **argv);

/*
init
*/
int		init_rule(t_rule *rule, int argc, char **argv);
int		init_mutex(t_rule *rule, t_mutex *mutex);
void	init_philo_data(t_philo *ph, t_rule *rule, t_mutex *mutex, int i);
int		init_philo(t_philo **phs, t_rule *rule, t_mutex *mutex);

/*
state
*/
void	take_fork(t_philo *ph);
void	eat(t_philo *ph);
void	sleep_and_think(t_philo *ph);

/*
clear
*/
int		clear_mutex_error(t_mutex *mutex, int cnt, int flag);
int		clear_mutex(t_mutex *mutex, t_rule *rule);
int		clear_all(t_philo *philos, int ret);

#endif