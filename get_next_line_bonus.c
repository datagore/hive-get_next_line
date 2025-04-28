/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:59:37 by abostrom          #+#    #+#             */
/*   Updated: 2025/04/28 16:46:12 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_buffer	*get_buffer(t_buffer **buffer_list, int file)
{
	t_buffer	*buffer;

	buffer = *buffer_list;
	while (buffer != NULL && buffer->file != file)
		buffer = buffer->next;
	if (buffer != NULL)
		return (buffer);
	buffer = malloc(sizeof(t_buffer));
	if (buffer == NULL)
		return (NULL);
	buffer->next = *buffer_list;
	buffer->file = file;
	buffer->length = 0;
	*buffer_list = buffer;
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
	static t_buffer	*buffer_list;
	char			*line;
	size_t			length;
	t_buffer		*buffer;

	line = NULL;
	buffer = get_buffer(&buffer_list, file);
	if (buffer == NULL)
		return (NULL);
	length = 1;
	while (length > 0)
	{
		length = read_buffer(buffer);
		line = append(line, buffer->start, length);
		buffer->start += length;
		buffer->length -= length;
		if (ft_strchr(line, '\n') != NULL)
			return (line);
	}
	free_buffer(&buffer_list, file);
	return (line);
}
