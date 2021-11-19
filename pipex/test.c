#include <unistd.h>

int	main(int argc, char **argv)
{
	char *envp[] = {0};

	execve("../.", argv, envp);
	return (0);
}
