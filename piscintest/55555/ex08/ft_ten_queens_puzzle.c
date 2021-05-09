/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:04:50 by jseol             #+#    #+#             */
/*   Updated: 2021/03/13 19:30:27 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char g_col[11];

int	check(int i)
{
	int k;
	int x;
	int y;

	k = 0;
	while (k < i)
	{
		x = g_col[i] - g_col[k];
		y = i - k;
		if (x < 0)
			x *= -1;
		if (y < 0)
			y *= -1;
		if (g_col[i] == g_col[k] || x == y)
			return (0);
		k++;
	}
	return (1);
}

int	queens(int i)
{
	int j;
	int cnt;

	cnt = 0;
	if (i == 10)
	{
		write(1, g_col, 10);
		write(1, "\n", 1);
		cnt++;
	}
	else
	{
		j = 0;
		while (j < 10)
		{
			g_col[i] = j + '0';
			if (check(i))
				cnt += queens(i + 1);
			j++;
		}
	}
	return (cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int cnt;

	cnt = queens(0);
	return (cnt);
}
#include<stdio.h>
int main()
{
	printf("%d", ft_ten_queens_puzzle());
}
