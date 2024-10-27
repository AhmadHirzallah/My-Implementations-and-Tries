#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef enum	e_modes
{
	INITAILIZATION,
	LINE_SETTING_UP
}						t_modes_e;

typedef struct s_gnl
{
	char	left_over[1024][BUFFER_SIZE];
	char	buffer[BUFFER_SIZE];
	long	size_lft_ovr[1024];
	long	count_new_lines[1024];
	char	*tmp1;
	char	*tmp2;
	int		fd;
	long	size_temp;
	long	temp_len;
	char	*line;
}						t_gnl_s;

#endif