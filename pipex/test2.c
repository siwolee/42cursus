/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/02/09 22:53:48 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

#define IN_A 0
#define OUT_A 1
#define IN_B 2
#define OUT_B 3
// IN :  홀수일 때 a 짝수일 때 b (짝수시작)
// OUT : 홀수일 때 b 짝수일 때 a
// #define IN(x) (x % 2 == 1 ? IN_B : IN_A)
// #define OUT(x) (x % 2 == 1 ? OUT_A : OUT_B)
#define INFILE 4
#define OUTFILE 5

int	fd_in(int i)
{
	// if (i == 2)
	// 	return (INFILE);
	if (i % 2)
		return (IN_B);
	else
		return (IN_A);
}

int	fd_out(int i, int ac)
{
	// if (i == ac - 2)
	// 	return (OUTFILE);
	ac = 1;
	if (i % 2)
		return (OUT_A);
	else
		return (OUT_B);
}


char **get_path (char *const *envp)
{
	int	i;
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
	{
		i++;
	}
	return (ft_split_replace(envp[i] + 5, ':', '/'));
}

char *check_executable(char *cmd, char **path)
{
	int i = 0;
	char *testcmd;

	i = 0;
	testcmd = NULL;
	while (path[i])
	{
		testcmd = ft_strjoin(path[i], cmd);
		if (access(testcmd, F_OK | X_OK) != -1)
			break ;
		free(testcmd);
		testcmd = 0;
		i++;
	}
	return (testcmd);
}

char **init_check(int ac, char **av, char *const *envp, int fd[])
{
	//heredoc 옵션 필요함
	if (ac < 4)
		exit(2);
	fd[INFILE] = open(av[1], O_RDONLY);
	if (fd[INFILE] < 0)
		exit(2);
	return (get_path(envp));
}

int	child_proc(int fd_in, int fd_out, char **path, char **cmd, char *const *envp)
{
	printf("print.. in%d out%d %s\n",fd_in, fd_out, *cmd);
	if (dup2(fd_in, STDIN_FILENO) == -1)
		printf("dup in fail\n");
	// else
	// 	printf("dup in success\n");
	close(fd_in);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		printf("dup out fail\n");
	// else
		// printf("dup out success\n");
	// printf("dfdfsfsdafsdf\n");
	close(fd_out);
	if (execve(check_executable(*cmd, path), cmd, envp) == -1)
		printf("failllllllll\n");
	return (1);
}


int main(int ac, char **av, char **envp)
{
	int 	fd[6];
	pid_t	pid;
	int		i;
	// char	*buf;
	int 	status;
	char **path;

	//매개변수 갯수 검사, 실행 가능한 커맨드인지 검사 후 av(실행을 위한 명령어 목록)으로 재할당 받음
	path = init_check(ac, av, envp, fd);
	fd[OUTFILE] = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 777);
	if (fd[OUTFILE] < 0)
	{
		printf("outfile problem\n");
		exit(2);
	}
	pipe(fd); //0,1 열림
	pipe(fd + 2); //2,3 열림
	printf("parent : infile%d, outfile%d in_a%d out_a%d in_b%d out_b%d\n", fd[INFILE], fd[OUTFILE], fd[0], fd[1], fd[2], fd[3]);
	i = 1;
	while (++i < ac - 1)
	{
		pid = fork();
		if (pid != 0)
		{
			// wait(&status);
			continue ;
		}
		// close(fd[fd_in(i + 1)]);
		// close(fd[fd_out(i + 1, ac)]);
		if (i == 2)
		{
			// close(fd[fd_in(i)]);
			child_proc(fd[INFILE], fd[fd_out(i, ac)], path, ft_split(av[i], ' '), envp);
		}
		else if (i == ac - 2)
		{
			// close(fd[fd_out(i, ac)]);
			printf("outfile name : %s\n", av[ac-1]);
			child_proc(fd[fd_in(i)], fd[OUTFILE], path, ft_split(av[i], ' '), envp);
		}
		else
			child_proc(fd[fd_in(i)], fd[fd_out(i, ac)], path, ft_split(av[i], ' '), envp);
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	close(fd[4]);
	close(fd[5]);
	wait(&status);
	free(path);
}
