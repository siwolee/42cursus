#include "get_next_line.h"

int main()
{
	int	fd;

	fd = open("aaa.txt");
	if (fd < 0)
		return (0);
	while (1)
	{
		get_next_line(1);
	}
	close(fd);
}