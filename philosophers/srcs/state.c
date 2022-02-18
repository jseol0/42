/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:19:52 by jaeyu             #+#    #+#             */
/*   Updated: 2022/02/11 19:55:17 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_usleep(t_philo *ph, long time)
{
	long	start;

	start = get_time(ph->start_tv);
	while (get_time(ph->start_tv) - start < time)
		usleep(100);
}

void	take_fork(t_philo *ph)
{
	pthread_mutex_lock(&ph->mutex->fork[ph->l_fork]);
	pthread_mutex_lock(&ph->mutex->m_out);
	printf("%ld\t%d\thas taken a fork\n", get_time(ph->start_tv), ph->id + 1);
	pthread_mutex_unlock(&ph->mutex->m_out);
	pthread_mutex_lock(&ph->mutex->fork[ph->r_fork]);
	pthread_mutex_lock(&ph->mutex->m_out);
	printf("%ld\t%d\thas taken a fork\n", get_time(ph->start_tv), ph->id + 1);
	pthread_mutex_unlock(&ph->mutex->m_out);
}

void	eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->mutex->m_data);
	ph->eat_cnt++;
	gettimeofday(&ph->life_tv, NULL);
	pthread_mutex_unlock(&ph->mutex->m_data);
	pthread_mutex_lock(&ph->mutex->m_out);
	printf("%ld\t%d\tis eating\n", get_time(ph->start_tv), ph->id + 1);
	pthread_mutex_unlock(&ph->mutex->m_out);
	ft_usleep(ph, ph->rule->time_eat);
	pthread_mutex_unlock(&ph->mutex->fork[ph->l_fork]);
	pthread_mutex_unlock(&ph->mutex->fork[ph->r_fork]);
}

void	sleep_and_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->mutex->m_out);
	printf("%ld\t%d\tis sleeping\n", get_time(ph->start_tv), ph->id + 1);
	pthread_mutex_unlock(&ph->mutex->m_out);
	ft_usleep(ph, ph->rule->time_sleep);
	pthread_mutex_lock(&ph->mutex->m_out);
	printf("%ld\t%d\tis thinking\n", get_time(ph->start_tv), ph->id + 1);
	pthread_mutex_unlock(&ph->mutex->m_out);
}
