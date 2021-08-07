#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		temp;
	int		fd;
	char	*line;
	int i = 0;

	fd = open("test.fdf", O_RDONLY);
	while ((temp = (get_next_line(fd, &line)) > 0))
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	printf("%s\n", line);
	printf("%d\n", i);
	free(line);
	close(fd);
	return (0);
}
