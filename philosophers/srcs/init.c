/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:01:34 by jaeyu             #+#    #+#             */
/*   Updated: 2022/03/02 18:16:56 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_rule(t_rule *rule, int argc, char **argv)
{
	memset(rule, 0, sizeof(t_rule));
	rule->philo_num = ft_atoi(argv[1]);
	rule->time_die = ft_atoi(argv[2]);
	rule->time_eat = ft_atoi(argv[3]);
	rule->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rule->must_eat = ft_atoi(argv[5]);
	else
		rule->must_eat = -1;;
	return (0);
}

int	init_mutex(t_rule *rule, t_mutex *mutex)
{
	int	i;

	memset(mutex, 0, sizeof(t_mutex));
	mutex->fork = malloc(sizeof(pthread_mutex_t) * rule->philo_num);
	if (mutex->fork == NULL)
		return (1);
	i = 0;
	while (i < rule->philo_num)
	{
		if (pthread_mutex_init(&mutex->fork[i], NULL))
			return (clear_mutex_error(mutex, i, 1));
		i++;
	}
	if (pthread_mutex_init(&mutex->m_out, NULL))
		return (clear_mutex_error(mutex, rule->philo_num, 1));
	if (pthread_mutex_init(&mutex->m_data, NULL))
		return (clear_mutex_error(mutex, rule->philo_num, 0));
	return (0);
}

void	init_philo_data(t_philo *ph, t_rule *rule, t_mutex *mutex, int i)
{
	ph->id = i;
	ph->l_fork = i;
	ph->r_fork = (i + 1) % rule->philo_num;
	ph->eat_cnt = 0;
	ph->rule = rule;
	ph->mutex = mutex;
	gettimeofday(&ph->start_tv, NULL);
	ph->life_tv = ph->start_tv;
}

int	init_philo(t_philo **phs, t_rule *rule, t_mutex *mutex)
{
	int		i;
	t_philo	*ph;

	ph = malloc(sizeof(t_philo) * rule->philo_num);
	if (ph == NULL)
		return (1);
	i = -1;
	while (++i < rule->philo_num)
		init_philo_data(&ph[i], rule, mutex, i);
	i = -1;
	while (++i < rule->philo_num)
	{
		if (pthread_create(&ph[i].thread, NULL, routine, (void *)&ph[i]))
		{
			free(ph);
			return (1);
		}
		pthread_detach(ph[i].thread);
		usleep(70);
	}
	*phs = ph;
	return (0);
}
