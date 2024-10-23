/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:43:28 by ahirzall          #+#    #+#             */
/*   Updated: 2024/10/19 21:43:29 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_gnl	gnl;

	gnl.line = NULL;
	gnl.fd = fd;
	if (fd > 1023 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!gnl.count_newlns[fd])
		gnl_read_file(&gnl, -1, 0, 0);
	else
		gnl_copy_from_leftover(&gnl);
	return (gnl.line);
}
