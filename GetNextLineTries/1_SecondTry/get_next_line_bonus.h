/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:38:33 by okraus            #+#    #+#             */
/*   Updated: 2024/10/17 09:42:05 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	char	leftover[1024][BUFFER_SIZE];
	char	buffer[BUFFER_SIZE];
	long		size_lft_ovr[1024];	//how many chars in leftover
	long		count_newlns[1024];	//how many newlines in leftover
	char	*temp;
	char	*temp2;
	long		fd;
	long		size_temp;		//how big is temp
	long		length_temp;	//how many chars in temp
	char	*line;
}	t_gnl;

char	*get_next_line(long fd);

#endif
