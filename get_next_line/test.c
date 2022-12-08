#include "get_next_line.h"
#include "stdio.h"

int main()
{
	int	fd;
	int	res;
	char	*s;

	fd = open("./aaa.txt",  O_RDONLY);
	// fd = 1;
	if (fd < 0)
		return (0);
	res = 1;
	while (1)
	{
		s = get_next_line(fd);
		res = printf("%s", s);
		if (!s)
		{
			break ;
		}
		free(s);
	}
	close(fd);
}