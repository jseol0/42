/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:54:46 by jaeyu             #+#    #+#             */
/*   Updated: 2022/03/02 19:40:06 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_mutex_error(t_mutex *mutex, int cnt, int flag)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		pthread_mutex_destroy(&mutex->fork[i]);
		i++;
	}
	free(mutex->fork);
	if (!flag)
		pthread_mutex_destroy(&mutex->m_out);
	return (1);
}

int	clear_mutex(t_mutex *mutex, t_rule *rule)
{
	int		i;

	pthread_mutex_destroy(&mutex->m_out);
	pthread_mutex_destroy(&mutex->m_data);
	i = 0;
	while (i < rule->philo_num)
	{
		pthread_mutex_destroy(&mutex->fork[i]);
		i++;
	}
	free(mutex->fork);
	return (1);
}

int	clear_all(t_philo *philos, int ret)
{
	clear_mutex(philos->mutex, philos->rule);
	free(philos);
	return (ret);
}
