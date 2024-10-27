#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	gnl_read_extra(t_gnl_s *gnl_s, long r, t_modes_e mode)
{
	if (mode == INITAILIZATION)
	{
		gnl_s->size_temp = BUFFER_SIZE * 2;
		gnl_s->tmp1 = malloc(gnl_s->size_temp);
		if (gnl_s->tmp1)
		{
			r = -1;
			while (++r < gnl_s->size_lft_ovr[gnl_s->fd])
				gnl_s->tmp1[r] = gnl_s->left_over[gnl_s->fd][r];
		}
		gnl_s->temp_len = gnl_s->size_lft_ovr[gnl_s->fd];
		gnl_s->size_lft_ovr[gnl_s->fd] = 0;
		gnl_s->count_new_lines[gnl_s->fd] = 0;
	}
	else if (LINE_SETTING_UP == mode)
	{
		if (gnl_s->tmp1 && gnl_s->temp_len)
		{
			gnl_s->line = malloc(gnl_s->temp_len + 1);
			r = -1;
			while (gnl_s->line && ++r < gnl_s->temp_len)
				gnl_s->line[r] = gnl_s->tmp1[r];
			if (gnl_s->line)
				gnl_s->line[r] = '\0';
		}
		free (gnl_s->tmp1);
	}
}

void	gnl_double_tmp(t_gnl_s *gnl_s, long *iter)
{
	long	i;

	(*iter)++;
	if (((*iter + 2) * BUFFER_SIZE) > gnl_s->size_temp);
	{
		gnl_s->tmp2 = malloc((gnl_s->size_temp) * 2);
		if (gnl_s->tmp2)
		{
			gnl_s->size_temp *= 2;
			i = -1;
			while (++i < gnl_s->temp_len)
			{
				gnl_s->tmp2[i] = gnl_s->tmp1[i];
			}
		}
		free(gnl_s->tmp1);
		gnl_s->tmp1 = gnl_s->tmp2;
	}

}

void	gnl_read_file(t_gnl_s *gnl_s, long r, long i, long iter)
{
	gnl_read_extra(gnl_s, r, INITAILIZATION);
	r = 1;
	while ((r > 0) && (gnl_s->tmp1) && !(gnl_s->count_new_lines[gnl_s->fd]))
	{
		r = read(gnl_s->fd, gnl_s->buffer, BUFFER_SIZE);
		if (r < 0)
		{
			free (gnl_s->tmp1);
			return ;
		}
		i = 0;
		while ((i < r) && (!i || (gnl_s->buffer[i - 1] != '\n')))
			gnl_s->tmp1[gnl_s->temp_len++] = gnl_s->buffer[i++];
		while (i < r)
		{
			if (gnl_s->buffer[i] == '\n')
				gnl_s->count_new_lines[gnl_s->fd]++;
			gnl_s->left_over[gnl_s->fd][gnl_s->size_lft_ovr[gnl_s->fd]++]\
						= gnl_s->buffer[i];
			i++;
		}
		if (gnl_s->temp_len &&
			(gnl_s->tmp1[gnl_s->temp_len - 1] == '\n'))
			break;
		gnl_double_tmp(gnl_s, &iter);
	}
	gnl_read_extra(gnl_s, r, LINE_SETTING_UP);
	
}

void	gnl_cpy_frm_left_over(t_gnl_s *gnl)
{
	long i;
	long j;
	long k;

	i = -1;
	while (gnl->left_over[gnl->fd][++i] != '\n')
		;
	gnl->line = malloc(i + 2);
	if (!gnl->line)
	{
		gnl->count_new_lines[gnl->fd] = 0;
		gnl->size_lft_ovr[gnl->fd] = 0;
		return ;
	}
	gnl->count_new_lines[gnl->fd]--;
	j = -1;
	while (++j <= i)
		gnl->line[j] = gnl->left_over[gnl->fd][j];
	gnl->line[j] = '\0';
	k = -1;
	while ((j + (++k)) < gnl->size_lft_ovr[gnl->fd])
		gnl->left_over[gnl->fd][k] = gnl->left_over[gnl->fd][k + j];
	gnl->size_lft_ovr[gnl->fd] = k;
	
	

	
}


char	*get_next_line(int fd)
{
	static t_gnl_s	gnl;

	gnl.line = NULL;
	gnl.fd = fd;

	if (fd > 1023 || fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!gnl.count_new_lines[fd])
		gnl_read_file(&gnl, -1, 0, 0);
	else
		gnl_cpy_frm_left_over(&gnl);
	return (gnl.line);
}

int main (void)
{
	int	fd;
	char *a;

	fd = open("hi.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error Opening File\n");
		return (1);
	}
	printf("\nFile with fd = [%d]\n---------\n", fd);
	while ((a = get_next_line(fd)) != NULL)
	{
		printf("%s", a);
		free(a);
	}
	printf("-----[FINISHED]-----");
	
}