#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> // For the close() function

int	main(void)
{
	int		fd;
	char	*a;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((a = get_next_line(fd)) != NULL)
	{
		printf("%s", a);
		free(a); // Free the line after it's printed
	}
	close(fd); // Correctly close the file descriptor with close()
	return (0);
}
