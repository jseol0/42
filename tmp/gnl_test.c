#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_strdup(char *s)
{
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	char	line[1000000];
	char	buf[1];
	int		i;
	int		read_val;

	line[0] = 0;
	i = 0;
	while ((read_val = read(fd, buf, 1)) > 0)
	{
		line[i++] = buf[0];
		line[i] = 0;
		if (buf[0] == '\n')
			return (ft_strdup(line));
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}

int	main(void)
{
	char	*ret;
	int	fd = open("inter2.c", O_RDONLY);
	while ((ret = get_next_line(fd)))
		printf("%s", ret);
	return (0);
}