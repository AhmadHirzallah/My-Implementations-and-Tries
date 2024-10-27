/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:38:33 by okraus            #+#    #+#             */
/*   Updated: 2024/10/17 09:41:49 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	char	leftover[1024][BUFFER_SIZE];
	char	buffer[BUFFER_SIZE];
	long	size_lft_ovr[1024];
	long	count_newlns[1024];
	char	*temp;
	char	*temp2;
	int		fd;
	long	size_temp;
	long	length_temp;
	char	*line;
}			t_gnl;

void		gnl_copy_from_leftover(t_gnl *gnl);
void		gnl_read_file(t_gnl *gnl, long r, long i, long iter);
char		*get_next_line(int fd);

#endif
