햣 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseol <jseol@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:57:40 by jseol             #+#    #+#             */
/*   Updated: 2022/01/11 17:57:40 by jseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	non_bulitin_exec(t_cmd *cmd, char **env, int, pipe_fd);

int	non_bulitin(t_cmd *cmd, char **env, int pipe_fd[])
{
	if (경로 포함된 명령어)
	{
		non_bulitin_exec(cmd, env, pipe_fd);
	}
	else	// 경로 미포함 명령어
	{
		env 에서 PATH 찾기;
		ft_split 으로 합치기;
		while ()
		{
			strjoin 으로 경로 뒤에 /명령어 붙이기;
			if (stat 함수로 해당 경로에 명령어가 존재하면)
			{
				non_bulitin_exec(cmd, env, pipe_fd);
				break;
			}
		}
	}
	if (진행하면서 에러 상황이면)
		return (ERROR);
	return (0);
}

int	exec_funtion(t_cmd *cmd, char **env, int pipe_fd[])
{
	int	fd;

	if (redirection 유무 검사)
		redirection 처리;
	if (cmd->pipe_flag == 1 && (출력 리다이렉트가 아니면))
		fd = pipe_fd[1];
	else
		fd = STDOUT_FILENO;
	if ((ft_strncmp("echo", cmd->cmd_args[0], 4)) == 0)
		return (echo(cmd, fd));	//빌트인 명령어 검사후 처리
	else if ((ft_strncmp("cd", cmd->cmd_args[0], 2)) == 0)
		return (cd(cmd));
	else if ((ft_strncmp("pwd", cmd->cmd_args[0], 3)) == 0)
		return (pwd(fd));
	else if ((ft_strncmp("export", cmd->cmd_args[0], 6)) == 0)
		return (export(cmd, 환경변수, fd));
	else if ((ft_strncmp("unset", cmd->cmd_args[0], 5)) == 0)
		return (unset(cmd, 환경변수));
	else if ((ft_strncmp("env", cmd->cmd_args[0], 3)) == 0)
		return (env(환경변수, fd));
	else if ((ft_strncmp("exit", cmd->cmd_args[0], 4)) == 0)
		return (ft_exit(cmd));
	else if (non_bulitin(cmd, env, pipe_fd) == ERROR)
	{	
		에러처리
		return (ERROR);
	}
	return (0);
}

int	exec(t_cmd *cmd, char **env)
{
	int	fd[2];		//	main에서 stdin, stdout fd backup 해놓기
	int	status;
	int	exec_val;
	pid_t	pid;

	pipe(fd);
	if ((exec_val = exec_funtion(cmd, env, fd)) == ERROR);		//	여기서 redirect, 모든 명령어 분기점
		에러처리;
	else
		g_exit_status = exec_val;
	dup2(백없해둔 fd, STDIN_FILENO);
	dup2(백없해둔 fd, STDOUT_FILENO);
	if (cmd->pipe_flag)
	{
		if ((pid = fork()) < 0)
		{
			fork error 출력하고
			return (g_exit_status);
		}
	}
	else
		return (g_exit_status);
	if (pid == 0)	//	자식프로세스
	{
		dup2(fd[0], 0);
		close(fd[1]);
		g_exit_status = exec(cmd, env);	// 자식프로세스에서 실행될 명령어를 실행해주기 위해 다시 재귀
		exit(g_exit_status);
	}
	else	//	부모프로세스
	{
		waitpid(pid, &status, 0);	//	하위 8비트를 참조하여 자식 프로세스가 exit, _exit, _Exit에 넘겨준 인자값을 얻을 수 있음
		g_exit_status = status >> 8;
		return (g_exit_status);
	}
}

*************
**********exprot, unset 환경변수 어떻게 할지 물어보기
*************

******************bulitin 명령어 구현하기

builtin, redir	/	pipe, 내장 명령어

					fork 해야하는 경우



1. 리다이렉션 유무
		dup2 로 입출력fd 제어
2. builtin 유무
		cmd 실행
3. 파이프 유무 || 내장명령어 유무
		fork

고려사항

* exit_status 반환
* error handler
	- 모든 상황마다? or 한번에 처리
* <<
* exit 함수
	- exit_status 처리
	- exit 555 exit_status = 555
	- exit afsjdsf exit 되고 exit_status = 255
	- exit 123 345 인자 여러개 exit 안됨 exit_status = 1
