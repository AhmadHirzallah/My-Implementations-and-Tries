/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:40:10 by ahirzall          #+#    #+#             */
/*   Updated: 2024/09/29 16:40:14 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
