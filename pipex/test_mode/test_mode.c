#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd[6];
	int i;
	
	//666
	fd[0]= open("000", O_RDWR|O_TRUNC|O_CREAT, 0666);
	fd[1]= open("001", O_WRONLY|O_TRUNC|O_CREAT, 0666);
	//664
	fd[2]= open("002", O_RDWR|O_TRUNC|O_CREAT, 0664);
	fd[3]= open("003", O_WRONLY|O_TRUNC|O_CREAT, 0664);
	//644
	fd[4]= open("004", O_RDWR|O_TRUNC|O_CREAT, 0644);
	fd[5]= open("005", O_WRONLY|O_TRUNC|O_CREAT, 0644);

	i = 0;
	while (i < 5)
	{
		if (fd[i] < 0)
			printf("fd %d :: wrong file\n", i);
		else
			printf("fd %d = %d :: ok\n", i, fd[i]);
		close(fd[i]);
		i++;
	}
}