/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:33:27 by jseol             #+#    #+#             */
/*   Updated: 2021/03/11 13:54:54 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int			ft_strcmp(char *str1, char *str2)
{
	int		i;

	i = 0;
	while (str1[i] != '\0' && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void		ft_sort_params(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		j = 2;
		while (j < argc)
		{
			if (ft_strcmp(argv[j - 1], argv[j]) > 0)
			{
				tmp = argv[j - 1];
				argv[j - 1] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	int		i;

	i = 1;
	ft_sort_params(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
