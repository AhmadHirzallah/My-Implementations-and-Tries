/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:43:35 by ahirzall          #+#    #+#             */
/*   Updated: 2024/10/19 21:43:37 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>

static size_t	calc_len_till_newline(t_linked_lst *lst_node)
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

static char	*get_one_line(t_linked_lst *lst_node)
{
	char	*line_str;
	size_t	str_size;

	if (NULL == lst_node)
		return (NULL);
	str_size = calc_len_till_newline(lst_node);
	line_str = malloc(str_size + 1);
	if (NULL == line_str)
		return (NULL);
	concat_strs_into_line(lst_node, line_str);
	return (line_str);
}

t_linked_lst	*find__get_last_node(t_linked_lst *lnkd_lst)
{
	if (NULL == lnkd_lst)
		return (NULL);
	while (lnkd_lst->next_node)
		lnkd_lst = lnkd_lst->next_node;
	return (lnkd_lst);
}

static void	prepare_lnkd_lst_for_next(t_linked_lst **lnked_lst)
{
	t_linked_lst	*last_node;
	t_linked_lst	*clean_new_node;
	size_t			i;
	size_t			j;

	clean_new_node = malloc(sizeof(t_linked_lst));
	clean_new_node->str_buf_content = malloc(BUFFER_SIZE + 1);
	if ((NULL == clean_new_node) || (NULL == clean_new_node->str_buf_content))
		return ;
	last_node = find__get_last_node(*lnked_lst);
	i = 0;
	j = 0;
	while ((last_node->str_buf_content[i])
		&& last_node->str_buf_content[i] != '\n')
		++i;
	while (last_node->str_buf_content[i] && (last_node->str_buf_content[++i]))
		clean_new_node->str_buf_content[j++] = last_node->str_buf_content[i];
	clean_new_node->str_buf_content[j] = '\0';
	clean_new_node->next_node = NULL;
	destroy_linked_list(lnked_lst, clean_new_node);
}

char	*get_next_line(int fd)
{
	static t_linked_lst	*list_head = NULL;
	char				*line_str;

	if (fd < 0 || (BUFFER_SIZE <= 0) || BUFFER_SIZE > 1000000 || fd > 1024)
		return (NULL);
	begin_lines_into_lnked_lst(&list_head, fd);
	if (!list_head)
		return (NULL);
	line_str = get_one_line(list_head);
	prepare_lnkd_lst_for_next(&list_head);
	return (line_str);
}
/*
int	main(void)
{
	int		fd;
	char	*a;

	fd = open("test.txt", O_RDONLY);
	while ((a = get_next_line(fd)))
	{
		printf("%s", a);
	}
	// printf("%s", get_next_line(fd));
	return (0);
}
*/
