/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 10:53:51 by jseol             #+#    #+#             */
/*   Updated: 2021/05/07 12:11:04 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ret;
	int				i;

	ret = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ret[i] = (unsigned char)c;
		i++;
	}
	return (ret);
}
