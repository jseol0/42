#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int fd;
	char *line;
	int i;

	fd = open("test.txt",O_RDONLY);
	i = 1;
	while (i < 20)
	{
		int ret = get_next_line(fd, &line);
 		printf("line %d: %s ret: %d\n", i, line, ret);
		free(line);
		line = 0;
		i++;
 	}
	while (1);
}
