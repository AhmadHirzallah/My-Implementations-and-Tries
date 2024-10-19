/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:43:50 by ahirzall          #+#    #+#             */
/*   Updated: 2024/10/19 21:43:51 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"

static bool	is_newline(t_linked_lst *list_node)
{
	size_t	size;

	if (NULL == list_node)
		return (false);
	while (list_node)
	{
		if (!list_node->str_buf_content)
			return (false);
		size = 0;
		while ((list_node->str_buf_content[size]) && (size < BUFFER_SIZE))
		{
			if (list_node->str_buf_content[size] == '\n')
				return (true);
			size++;
		}
		list_node = list_node->next_node;
	}
	return (false);
}

static void	add_into_lnked_lst(t_linked_lst **lnked_lst, char *filled_bfr)
{
	t_linked_lst	*new_node;
	t_linked_lst	*last_node;

	if (!filled_bfr)
		return ;
	new_node = malloc(sizeof(t_linked_lst));
	if (!new_node)
		return ;
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

void	begin_lines_into_lnked_lst(t_linked_lst **lnked_lst, int fd)
{
	int		char_read_size;
	char	*to_fill_buf;

	while (!(is_newline(*lnked_lst)))
	{
		to_fill_buf = malloc(BUFFER_SIZE + 1);
		char_read_size = read(fd, to_fill_buf, BUFFER_SIZE);
		if (char_read_size == 0 || char_read_size == -1)
		{
			if (char_read_size == 0)
				free(to_fill_buf);
			else if (char_read_size == -1)
			{
				free(to_fill_buf);
				destroy_linked_list(lnked_lst, NULL);
			}
			return ;
		}
		to_fill_buf[char_read_size] = '\0';
		add_into_lnked_lst(lnked_lst, to_fill_buf);
	}
}

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
			return ;
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

void	destroy_linked_list(t_linked_lst **lnked_lst,
		t_linked_lst *clean_new_node)
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
	if (clean_new_node)
	{
		if (clean_new_node->str_buf_content[0])
			*lnked_lst = clean_new_node;
		else
		{
			free(clean_new_node->str_buf_content);
			free(clean_new_node);
		}
	}
}
