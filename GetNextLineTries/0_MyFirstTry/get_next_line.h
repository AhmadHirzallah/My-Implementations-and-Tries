/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:43:59 by ahirzall          #+#    #+#             */
/*   Updated: 2024/10/19 21:44:00 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_linked_lst
{
	char				*str_buf_content;
	struct s_linked_lst	*next_node;
}						t_linked_lst;

char					*get_next_line(int fd);
void					begin_lines_into_lnked_lst(t_linked_lst **lnked_lst,
							int fd);
void					concat_strs_into_line(t_linked_lst *lst_node,
							char *line_str);
void					destroy_linked_list(t_linked_lst **lnked_lst,
							t_linked_lst *clean_new_node);
t_linked_lst			*find__get_last_node(t_linked_lst *lnkd_lst);

#endif
