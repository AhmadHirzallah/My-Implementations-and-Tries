#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_linked_lst
{
	char				*str_buf_content;
	struct s_linked_lst	*next_node;
}						t_linked_lst;

char					*get_next_line(int fd);
size_t					calc_len_till_newline(t_linked_lst *lst_node);
void					concat_strs_into_line(t_linked_lst *lst_node,
							char *line_str);
char					*get_line(t_linked_lst *lst_node);
void					prepare_lnkd_lst_for_next(t_linked_lst **lnked_lst);
void					destroy_linked_list(t_linked_lst **lnked_lst,
							t_linked_lst *clean_new_node);

#endif
