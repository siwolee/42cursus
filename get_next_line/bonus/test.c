// #include "get_next_line_bonus.h"
#include "get_next_line.h"
#include "stdio.h"

int main()
{
	int	fd;
	int fd2;
	int fd3;
	int	res;
	char	*s;
	char	*ss;
	char	*sss;
	int		flag;

	fd = open("./a.txt",  O_RDONLY);
	fd2 = -1;
	fd3 = open("./c.txt",  O_RDONLY);
	
	res = 1;
	flag = 0;
	while (flag < 3)
	{
		if ((s = get_next_line(fd)) != NULL)
		{
			printf("a: %s", s);
			free(s);
		}
		else
			flag++;
		if ((ss = get_next_line(fd2)) != NULL)
		{
			printf("b: %s", ss);
			free(ss);
		}
		else
			flag++;
		if ((sss = get_next_line(fd3)) != NULL)
		{
			printf("c: %s", sss);
			free(sss);
		}
		else
			flag++;
	}
	close(fd);
	close(fd2);
	close(fd3);
}