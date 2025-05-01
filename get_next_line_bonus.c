/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:59:37 by abostrom          #+#    #+#             */
/*   Updated: 2025/05/01 13:04:05 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int file)
{
	static t_buffer	buffer_array[MAX_FILES];
	t_buffer		*buf;
	char			*line;
	size_t			length;

	if (file < 0 || file >= MAX_FILES)
		return (NULL);
	length = 1;
	line = NULL;
	buf = &buffer_array[file];
	buf->file = file;
	while (length > 0 && !ft_strchr(line, '\n'))
	{
		length = read_buffer(buf);
		line = append(line, buf->data + buf->head, length);
		buf->head += length;
	}
	return (line);
}
