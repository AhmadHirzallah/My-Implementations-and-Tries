/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:37:57 by okraus            #+#    #+#             */
/*   Updated: 2024/10/17 09:39:34 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_double_temp(t_gnl *gnl, long *iter)
{
	long	i;

	(*iter)++;
	if ((*iter + 2) * BUFFER_SIZE > gnl->size_temp)
	{
		gnl->temp2 = malloc(gnl->size_temp * 2);
		if (gnl->temp2)
		{
			gnl->size_temp *= 2;
			i = -1;
			while (++i < gnl->length_temp)
				gnl->temp2[i] = gnl->temp[i];
		}
		free(gnl->temp);
		gnl->temp = gnl->temp2;
	}
}

static void	gnl_read_file_extra(t_gnl *gnl, long r, short mod)
{
	// mod (تعني التعديل) ،  فهي تشير ما إذا كنت تريد ان تعدل ام لا فإن كان لا فهو إيلس فيعني ان تبدأ من الصفر
	if (mod)
	{
		r = -1;
		if (gnl->temp && gnl->length_temp)
		{
			gnl->line = malloc(gnl->length_temp + 1);
			while (gnl->line && ++r < gnl->length_temp)
				gnl->line[r] = gnl->temp[r];
			if (gnl->line)
				gnl->line[r] = '\0';
		}
		free(gnl->temp);
	}
	else
	{
		gnl->temp = malloc(BUFFER_SIZE * 2);
		if (gnl->temp)
			while (++r < gnl->size_lft_ovr[gnl->fd])
				gnl->temp[r] = gnl->leftover[gnl->fd][r];
		gnl->length_temp = gnl->size_lft_ovr[gnl->fd];
		gnl->size_temp = BUFFER_SIZE * 2;
		gnl->size_lft_ovr[gnl->fd] = 0;
		gnl->count_newlns[gnl->fd] = 0;
	}
}

static void	gnl_read_file(t_gnl *gnl, long r, long i, long iter)
{
	gnl_read_file_extra(gnl, r, 0);
	r = 1;
	while (r > 0 && gnl->temp && !gnl->count_newlns[gnl->fd])
	{
		r = read(gnl->fd, gnl->buffer, BUFFER_SIZE);
		if (r < 0)
		{
			free(gnl->temp);
			return ;
		}
		i = 0;
		while (i < r && (!i || gnl->buffer[i - 1] != '\n'))
			gnl->temp[gnl->length_temp++] = gnl->buffer[i++];
		while (i < r)
		{
			if (gnl->buffer[i] == '\n')
				gnl->count_newlns[gnl->fd]++;
			gnl->leftover[gnl->fd][gnl->size_lft_ovr[gnl->fd]++] = gnl->buffer[i++];
		}
		if (gnl->length_temp && gnl->temp[gnl->length_temp - 1] == '\n')
			break ;
		gnl_double_temp(gnl, &iter);
	}
	gnl_read_file_extra(gnl, r, 1);
}

static void	gnl_copy_from_leftover(t_gnl *gnl)
{
	long	i;
	long	j;
	long	k;

	i = 0;
	j = -1;
	k = -1;
	while (gnl->leftover[gnl->fd][i] != '\n')
		i++;
	gnl->line = malloc(i + 2);
	if (!gnl->line)
	{
		gnl->count_newlns[gnl->fd] = 0;
		gnl->size_lft_ovr[gnl->fd] = 0;
		return ;
	}
	gnl->count_newlns[gnl->fd]--;
	while (++j < i)
		gnl->line[j] = gnl->leftover[gnl->fd][j];
	gnl->line[j] = gnl->leftover[gnl->fd][j];
	gnl->line[++j] = '\0';
	while (j + ++k < gnl->size_lft_ovr[gnl->fd])
		gnl->leftover[gnl->fd][k] = gnl->leftover[gnl->fd][j + k];
	gnl->size_lft_ovr[gnl->fd] = k;
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl;

	gnl.line = NULL;
	gnl.fd = fd;
	if (fd > 1023 || fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 1000000)
		return (NULL);
	if (!gnl.count_newlns[fd])
		gnl_read_file(&gnl, -1, 0, 0);
	else
		gnl_copy_from_leftover(&gnl);
	return (gnl.line);
}
