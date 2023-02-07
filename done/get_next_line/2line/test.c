#include "get_next_line.h"
#include "stdio.h"

int main()
{
	int	fd;
	int	res;
	char	*s;

	fd = open("./a.txt",  O_RDONLY);
	res = 1;
	while ((s = get_next_line(fd)) != NULL)
	{
		printf("%s", s);
		free(s);
	}
	close(fd);
	// system("leaks a.out");
}