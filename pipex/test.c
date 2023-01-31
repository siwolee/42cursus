#include "./include/pipex.h"

int main(int ac, char **av, char *const *envp)
{
	// int infile_fd;
	// char *argv[] = {"grep", "a1", NULL};
	
	// if ((infile_fd = open("infile", O_RDONLY)) < 0)
	// 	return (printf("error"));
	// if ((dup2(infile_fd, STDIN)) < 0)
	// 	return (printf("error"));
	ac = 0;
	av = 0;

	int i = 0;
	char **path;
	char *testcmd;
	char *cmd = "/grep";
	
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
	{
		i++;
	}
	path = ft_split(envp[i] + 5, ':');

	i = 0;
	while (path[i])
	{
		testcmd = ft_strjoin(path[i], cmd);
		if (access(testcmd, F_OK | X_OK) != -1)
			break;
		free(testcmd);
		testcmd = 0;
		i++;
	}
	printf("%s\n",testcmd);
	return (testcmd);
}