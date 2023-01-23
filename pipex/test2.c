#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int i;
	int e;
	int status;
	pid_t pid[3];
	int fd[2];
	// int fd_temp;
	char buffer[50];
	int size;
	int ret;


	i = 0;
	while (++i < ac)
	{
		if (access(av[i] , F_OK | W_OK) < 0)
		{
			printf("cannot access file\n");
			return (0);
		}
		printf("%s file check : OK \n", av[i]);
		i++;
	}
	i = 0;
	if (pipe(fd) < 0)
	{
		printf("cannot open pipe\n");
		return (0);
	}
	while (i < 2)
	{
		pid[i] = fork();
		if (pid[i] == -1)
		{
			printf("fork %d canceled : return\n", i);
			e = 0;
			while (e < i)
				waitpid(pid[e], &status, 0);
		}
		else if (pid[i] == 0)
		{
			// fd_temp = open(av[1], O_RDWR);
			// if ((size = read(fd_temp, buffer, 50)) < 0)
			// {
			// 	printf("cannnot read file\n");
			// 	return (i);
			// }
			// close(fd_temp);
			write(fd[1], "HI\n", 3);
			printf("%d 자식 프로세스가 완료되었습니다.\n", i);
			return (i);
		}
		else if (pid[i] == 1)
		{
			read(fd[0], buffer, 50);
			printf("%s", buffer);
			printf("%d자식 프로세스가 완료되었습니다.\n", i);
		}
		i++;
	}
	printf("부모 프로세스입니다\n");
	e = 0;
	while (e < i)
	{
		ret = waitpid(pid[e],&status, 0);
		printf("기다렸습니다 : 자식 pid %d, %d번째\n", ret, e);
		printf("Exit code : %d, signal : %d \n", WEXITSTATUS(status), WTERMSIG(status));
		e++;
	}
	printf("정상 종료되었습니다.\n");
}
