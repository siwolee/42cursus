#include "get_next_line_bonus.h"
#include <stdio.h>

int	main()
{
	int	fd;
	char *line;

	fd = open("1char.txt", O_RDONLY);
	while((line = get_next_line(fd)))
	{
		printf("%s", line);
	}
}
