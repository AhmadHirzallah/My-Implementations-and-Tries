#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <fcntl.h>


int	main()
{
	int	fd;

    fd = open("file.txt", O_RDWR | O_CREAT, 0644);  // Open with read/write access

    if (fd == -1)  // Check for failure
    {
        perror("Error opening file");
        return 1;
    }

	dup2(fd, 1);

    close(fd);   // Always close the file descriptor after use

    return 0;
}