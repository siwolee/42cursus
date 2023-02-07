#include "test.h"

int main()
{
	int fd;
	char *s;

	fd = open("ttt.txt", O_RDONLY);
	while ((s = get_next_line(fd)))
	{
		ft_putstr_fd(s, 1);

	}
	ft_putstr_fd("*SUCESS*\n", 1);
	close(fd);
	
}