#include "get_next_line_bonus.h"
#include "get_next_line.h"

t_linked_lst *find__get_last_node(t_linked_lst *lnkd_lst)
{
	if (NULL == lnkd_lst)
		return (NULL);
	while (lnkd_lst->next_node)
		lnkd_lst = lnkd_lst->next_node;
	return (lnkd_lst);
}

void	begin_lines_into_lnked_lst(t_linked_lst **lnked_lst, int fd)
{
	int	char_read_size;
	char	*to_fill_buf;

	while (!(is_newline(*lnked_lst)))
	{
		to_fill_buf = malloc(BUFFER_SIZE + 1);
		if (!(to_fill_buf))
			return ;
		char_read_size = read(fd, to_fill_buf, BUFFER_SIZE);
		if (char_read_size <= 0)
		{
			free(to_fill_buf);
			return ;
		}
		to_fill_buf[char_read_size] = '\0';
		add_into_lnked_lst(lnked_lst, to_fill_buf);
	}
}

