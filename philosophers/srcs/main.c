/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:01:22 by jaeyu             #+#    #+#             */
/*   Updated: 2022/02/18 16:44:14 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_died(t_philo *phs)
{
	int		i;

	i = 0;
	while (i < phs->rule->philo_num)
	{
		if (get_time(phs[i].life_tv) > phs->rule->time_die + 3)
		{
			pthread_mutex_lock(&phs->mutex->m_out);
			printf("%ld\t%d\tdied\n", get_time(phs[i].start_tv), i + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_all_eat(t_philo *phs)
{
	int		i;

	i = 0;
	while (i < phs->rule->philo_num)
	{
		if (phs[i].eat_cnt < phs->rule->must_eat)
			return (0);
		i++;
	}
	pthread_mutex_lock(&phs->mutex->m_out);
	printf("%ld\t\tall philosophers ate it\n", get_time(phs->start_tv));
	return (1);
}

void	*monitor(void *philos)
{
	t_philo	*phs;

	phs = (t_philo *)philos;
	while (1)
	{
		usleep(1000);
		pthread_mutex_lock(&phs->mutex->m_data);
		if (is_died(phs))
			return (NULL);
		if (phs->rule->must_eat != -1 && is_all_eat(phs))
			return (NULL);
		pthread_mutex_unlock(&phs->mutex->m_data);
	}
}

void	*routine(void *philo)
{
	t_philo			*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		take_fork(ph);
		eat(ph);
		sleep_and_think(ph);
	}
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	t_rule		rule;
	t_mutex		mutex;
	pthread_t	thr_monitor;

	if (!is_valid_arg(argc, argv))
	{
		printf("Error: arguments\n");
		return (1);
	}
	if (init_rule(&rule, argc, argv))
	{
		printf("Error: rule\n");
		return (1);
	}
	if (init_mutex(&rule, &mutex) == 1)
		return (1);
	if (init_philo(&philos, &rule, &mutex) == 1)
		return (clear_mutex(&mutex, &rule));
	if (pthread_create(&thr_monitor, NULL, monitor, (void *)philos))
		return (clear_all(philos, 1));
	pthread_join(thr_monitor, NULL);
	return (clear_all(philos, 0));
}
