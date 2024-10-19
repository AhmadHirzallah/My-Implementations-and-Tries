#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include "get_next_line.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void			begin_lines_into_lnked_lst(t_linked_lst **lnked_lst, int fd);
t_linked_lst	*find__get_last_node(t_linked_lst *lnkd_lst);
bool			is_newline(t_linked_lst *list_node);
void			add_into_lnked_lst(t_linked_lst **lnked_lst, char *filled_bfr);

#endif