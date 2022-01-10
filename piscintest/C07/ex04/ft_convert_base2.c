/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:25:33 by jseol             #+#    #+#             */
/*   Updated: 2021/03/16 10:24:03 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			find_index(char c, char *base, int base_size)
{
	int i;

	i = 0;
	while (i < base_size)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_char_check(char str)
{
	if (str == ' ' || str == '\f' || str == '\n' || str == '\r'
		|| str == '\t' || str == '\v' || str == '+')
		return (1);
	else if (str == '-')
		return (-1);
	else
		return (0);
}

int			ft_base_check(char *base, int base_size)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = base;
	if (tmp[0] == '\0' || base_size == 1)
		return (0);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == ' ' || tmp[i] == '\f'
				|| tmp[i] == '\n' || tmp[i] == '\r'
				|| tmp[i] == '\t' || tmp[i] == '\v')
			return (0);
		j = i + 1;
		while (tmp[j] != '\0')
		{
			if (tmp[i] == tmp[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
