#include <stdio.h>
#include <stdlib.h>

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp;
	const char	*s;
	size_t		i;

	if (!dst && !src)
		return (0);
	tmp = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		tmp[i] = s[i];
		i++;
	}
	return (dst);
}

static int	is_set(char c, char set)
{
	if (c == set)
		return (1);
	else
		return (0);
}

static int	get_size(char const *s, char set)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (is_set(s[i], set))
		{
			i++;
			continue;
		}
		size++;
		while (!is_set(s[i], set) && s[i])
			i++;
	}
	return (size);
}

static char	**putret(char **ret, char const *s, char c)
{
	int		i;
	int		cnt;
	int		pivot;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (is_set(s[i], c))
		{
			i++;
			continue;
		}
		pivot = i;
		while (!is_set(s[i], c) && s[i] != '\0')
			i++;
		ret[cnt] = (char *)malloc(sizeof(char) * (i - pivot + 1));
		if (ret[cnt] == NULL)
			return (NULL);
		ft_memcpy(ret[cnt], s + pivot, i - pivot);
		ret[cnt][i - pivot] = '\0';
		cnt++;
	}
	ret[cnt] = NULL;
	return (ret);
}

char		**ft_split(char const *s, char c)
{
	char	**ret;
	int		ret_size;

	if (s == 0)
		return (0);
	ret_size = get_size(s, c);
	ret = (char **)malloc(sizeof(char *) * (ret_size + 1));
	if (ret == NULL)
		return (NULL);
	return (putret(ret, s, c));
}

int main (int argc, char **argv)
{
	char **ptr = ft_split(*(argv + 1), ' ');
	int arr[50];
	int pivot = 0;
	int i = 0;

	printf("%d\n", argc);
	for (int i = 0; *(ptr + i); i++)
	{	arr[i] = atoi(*(ptr + i));
		pivot++;
	}
	for (int i = 0; i < pivot; i++)
		printf("%d\n", arr[i]);

	return (0);
}
