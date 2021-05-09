/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:10:57 by jseol             #+#    #+#             */
/*   Updated: 2021/03/13 16:41:54 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int sum;

	if (nb < 0)
		return (0);
	i = 2;
	sum = 1;
	while (i <= nb)
	{
		sum *= i;
		i++;
	}
	return (sum);
}
