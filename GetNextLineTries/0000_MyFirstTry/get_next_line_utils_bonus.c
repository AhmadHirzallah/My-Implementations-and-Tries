#include "get_next_line.h"
#include "get_next_line_bonus.h"

bool	is_newline(t_linked_lst *list_node)
{
	size_t	size;

	if (NULL == list_node)
		return (false);
	
	while (list_node)
	{
		if (!list_node->str_buf_content)
			return (false);
		size = 0;
		while ((list_node->str_buf_content[size])
				&& (size < BUFFER_SIZE))
		{
			if (list_node->str_buf_content[size] == '\n')
				return (true);
			size++;
		
		}
		list_node = list_node->next_node;
	}
	return (false);
}


void	add_into_lnked_lst(t_linked_lst **lnked_lst, char *filled_bfr)
{
	t_linked_lst	*new_node;
	t_linked_lst	*last_node;

	if (!filled_bfr)
		return ;
	new_node = malloc(sizeof(t_linked_lst));
	if (!new_node)
		return;
	new_node->str_buf_content = filled_bfr;
	new_node->next_node = NULL;
	if (!*lnked_lst)	
		*lnked_lst = new_node;
	else
	{
		last_node = find__get_last_node(*lnked_lst);
		if (last_node)
			last_node->next_node = new_node;
	}
}