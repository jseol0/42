#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void ft_putstr_err(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	write(2, str, i);
}

int ft_execute(char **argv, int i, int tmp_fd, char **envp)
{
	argv[i] = NULL;
	close(tmp_fd);
	execve(argv[0], argv, envp);
	ft_putstr_err("error: cannot execute ");
	ft_putstr_err(argv[0]);
	ft_putstr_err("\n");
	return 1;
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	int i = 0;
	int pid = 0;
	int tmp_fd = dup(0);		// 표준입력 복사
	int fd[2];

	while(argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];		//	처음이면 앞으로 한칸 or ';' , '|' 로
		i = 0;
		while(argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))	// ';' , '|' or 끝까지 i++
			i++;
		if(strcmp(argv[0], "cd") == 0)
		{
			if(i != 2)
				ft_putstr_err("error: cd: bad arguments\n");
			else if(chdir(argv[1]) != 0)
			{
				ft_putstr_err("error: cd: cannot change directory to ");
				ft_putstr_err(argv[1]);
				ft_putstr_err("\n");
			}
		}
		else if(argv != &argv[i] && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			pid = fork();
			if(pid == 0)
			{
				dup2(tmp_fd, 0);		//	표준입력을 tmp_fd로
				if(ft_execute(argv, i, tmp_fd, envp))
					return 1;
			}
			else
			{
				close(tmp_fd);
				waitpid(-1, 0, 0);
				tmp_fd = dup(0);
			}
		}
		else if(argv != &argv[i] && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			pid = fork();
			if(pid == 0)
			{
				dup2(tmp_fd, 0);
				dup2(fd[1], 1);		// 표준출력을 파이브 입력으로
				close(fd[0]);
				close(fd[1]);
				if(ft_execute(argv, i, tmp_fd, envp))
					return 1;
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				waitpid(-1, 0, 0);
				tmp_fd = dup(fd[0]);
				close(fd[0]);
			}
		}
	}
	close(tmp_fd);
	return 0;
}
