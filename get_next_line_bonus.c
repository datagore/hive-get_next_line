/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:59:37 by abostrom          #+#    #+#             */
/*   Updated: 2025/04/28 14:59:41 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int file)
{
	static t_buffer	buffer;
	char			*line;
	size_t			length;

	line = NULL;
	buffer.file = file;
	while (1)
	{
		length = read_buffer(&buffer);
		line = append(line, buffer.start, length);
		buffer.start += length;
		buffer.length -= length;
		if (ft_strchr(line, '\n') != NULL || length <= 0)
			return (line);
	}
}
