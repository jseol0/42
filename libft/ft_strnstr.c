/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:59:01 by jseol             #+#    #+#             */
/*   Updated: 2021/05/08 17:27:05 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
int main(void)
{
	printf("%s\n", strnstr("ABC", "B", 2));
	printf("%s\n", ft_strnstr("ABC", "B", 2));

	printf("%s\n", strnstr("ABC", "B", 1));
	printf("%s\n", ft_strnstr("ABC", "B", 1));

	printf("%s\n", strnstr("ABC", "B", 5));
	printf("%s\n", ft_strnstr("ABC", "B", 5));

	printf("%s\n", strnstr("ABC", "X", 5));
	printf("%s\n", ft_strnstr("ABC", "X", 5));

	printf("%s\n", strnstr("ABC", "X", 2));
	printf("%s\n", ft_strnstr("ABC", "X", 2));

	printf("%s\n", strnstr("ABC", "ABCDEF", 3));
	printf("%s\n", ft_strnstr("ABC", "ABCDEF", 3));

	printf("%s\n", strnstr("ABC", "ABC", 3));
	printf("%s\n", ft_strnstr("ABC", "ABC", 3));


	printf("%s\n", strnstr("ABC", "ABC", 3));
	printf("%s\n", ft_strnstr("ABC", "ABC", 3));

	printf("%s\n", strnstr("A", "A", 3));
	printf("%s\n", ft_strnstr("A", "A", 3));

	printf("%s\n", strnstr("A", "A", 0));
	printf("%s\n", ft_strnstr("A", "A", 0));

	printf("%s\n", strnstr("A", "A", 1));
	printf("%s\n", ft_strnstr("A", "A", 1));

	printf("%s\n", strnstr("ABCDEF", "F", 1));
	printf("%s\n", ft_strnstr("ABCDEF", "F", 1));

	printf("%s\n", strnstr("ABCDEF", "F", 12));
	printf("%s\n", ft_strnstr("ABCDEF", "F", 12));

	printf("%s\n", strnstr("ABCDEF", "F", 6));
	printf("%s\n", ft_strnstr("ABCDEF", "F", 6));

	printf("%s\n", strnstr("ABCDEF", "F", 5));
	printf("%s\n", ft_strnstr("ABCDEF", "F", 5));

	printf("%s\n", strnstr("ABCDEF", "F", 7));
	printf("%s\n", ft_strnstr("ABCDEF", "F", 7));
	return (0);
}
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (needle[j] == haystack[i + j])
		{
			while (needle[j] != '\0' && i + j < len)
			{
				if (needle[j] != haystack[i + j])
					break;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
