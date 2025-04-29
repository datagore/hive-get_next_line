/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:59:37 by abostrom          #+#    #+#             */
/*   Updated: 2025/04/29 12:38:12 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_buffer	*get_buffer(t_buffer **list_head, int file)
{
	t_buffer	*buffer;

	buffer = *list_head;
	while (buffer != NULL && buffer->file != file)
		buffer = buffer->next;
	if (buffer != NULL)
		return (buffer);
	buffer = malloc(sizeof(t_buffer));
	if (buffer == NULL)
		return (NULL);
	buffer->next = *list_head;
	buffer->file = file;
	buffer->head = 0;
	buffer->tail = 0;
	*list_head = buffer;
	return (buffer);
}

static void	free_buffer(t_buffer **buffer, int file)
{
	t_buffer	*next;

	while (*buffer != NULL && (*buffer)->file != file)
		buffer = &(*buffer)->next;
	if (*buffer != NULL)
	{
		next = (*buffer)->next;
		free(*buffer);
		*buffer = next;
	}
}

char	*get_next_line(int file)
{
	static t_buffer	*list_head;
	char			*line;
	size_t			length;
	t_buffer		*b;

	b = get_buffer(&list_head, file);
	if (b == NULL)
		return (NULL);
	line = NULL;
	length = 1;
	while (length > 0 && !ft_strchr(line, '\n'))
	{
		length = read_buffer(b);
		line = append(line, b->data + b->head, length);
		b->head += length;
	}
	if (length <= 0)
		free_buffer(&list_head, file);
	return (line);
}
