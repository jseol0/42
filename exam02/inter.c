#include <unistd.h>

int	main(int argc, char **argv)
{
	char	buf[256] = {0, };
	int		i;
	int		j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
			{
				write (1, &argv[1][i], 1);
				buf[(unsigned char)argv[1][i]]++;
				break;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}