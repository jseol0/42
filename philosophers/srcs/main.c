/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyu <jaeyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:01:22 by jaeyu             #+#    #+#             */
/*   Updated: 2022/01/30 23:26:49 by jaeyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	init_philo(int	argc, char ** argv, t_philo *p)
{
	if (argc != 5 && argc != 6)
		ft_error("Too many input");
	if (!check_numeric(argv))
		ft_error("Numeric argument require");
	p->philo = ft_atoi(argv[1]);
	p->die = ft_atoi(argv[2]);
	p->eat = ft_atoi(argv[3]);
	p->sleep = ft_atoi(argv[4]);
	p->must_eat = -1;
	if (argc == 6)
		p->must_eat = ft_atoi(argv[5]);
	if (p->philo <= 0 || p->die <= 0 || p->eat <= 0 \
			|| p->sleep <= 0)
		ft_error("Invalid argument");
}

int main(int argc, char **argv)
{
	t_philo	p;

	init_philo(argc, argv, &p);

	return (0);
}