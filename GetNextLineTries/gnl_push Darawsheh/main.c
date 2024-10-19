#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int main()
{
	int	fd;
	char	*line;
	int	lines;

	lines = 1;
	fd = open("test.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
		printf("%d->%s\n", lines++ , line);
}
