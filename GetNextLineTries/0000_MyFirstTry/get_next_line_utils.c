#include "get_next_line.h"
#include "get_next_line_bonus.h"

void	concat_strs_into_line(t_linked_lst *lst_node, char *line_str)
{
	size_t	i;
	size_t	j;

	if (NULL == lst_node)
		return ;
	i = 0;
	while (lst_node)
	{
		if (!lst_node->str_buf_content)
			return;
		j = 0;
		while (lst_node->str_buf_content[j])
		{
			line_str[i] = lst_node->str_buf_content[j];
			if (lst_node->str_buf_content[j++] == '\n')
			{
				line_str[++i] = '\0';
				return ;
			}
			i++;
		}
		lst_node = lst_node->next_node;
	}
	line_str[i] = '\0';
}

size_t	calc_len_till_newline(t_linked_lst *lst_node)
{
	size_t	size;
	size_t	i;

	if (NULL == lst_node)
		return (0);
	size = 0;
	while (lst_node)
	{
		i = 0;
		while (lst_node->str_buf_content[i])
		{
			if (lst_node->str_buf_content[i] == '\n')
				return (size + 1);
			else
			{
				i++;
				size++;
			}
		}
		lst_node = lst_node->next_node;
	}
	return (size);
}

void	destroy_linked_list(t_linked_lst **lnked_lst, t_linked_lst *clean_new_node)
{
	t_linked_lst	*lnkd_lst_tmp_node;

	if (NULL == *lnked_lst)
		return ;
	while (*lnked_lst)
	{
		lnkd_lst_tmp_node = (*lnked_lst)->next_node;
		free((*lnked_lst)->str_buf_content);
		free(*lnked_lst);
		*lnked_lst = lnkd_lst_tmp_node;
	}
	*lnked_lst = NULL;
	if (clean_new_node->str_buf_content[0])
		*lnked_lst = clean_new_node;
	else
	{
		free(clean_new_node->str_buf_content);
		free(clean_new_node);
	}
}
