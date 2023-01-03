#include "../get_next_line.h"
#include "stdio.h"

int main()
{
	int	fd;
	char	*s;

	fd = open("./a.txt",  O_RDONLY);

	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	printf("\n");
	close(fd);
}
