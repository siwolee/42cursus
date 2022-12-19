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
	char	*tt = "a";

	fd = open("./a.txt",  O_RDONLY);
	fd2 = open("./b.txt",  O_RDONLY);
	fd3 = open("./c.txt",  O_RDONLY);
	
	res = 1;
	flag = 0;
	s = tt;
	ss = tt;
	sss = tt;

	while (s)
	{
		s = get_next_line(fd);
		printf("a: %s", s);
	}
	printf("\n");
	while (ss)
	{
		ss = get_next_line(fd2);
		printf("b: %s", ss);
	}	
	printf("\n");
	while (sss)
	{
		sss = get_next_line(fd3);
		printf("c: %s", sss);
	}
	printf("\n");
	close(fd);
	close(fd2);
	close(fd3);
}
