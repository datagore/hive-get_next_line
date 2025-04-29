/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:36:36 by abostrom          #+#    #+#             */
/*   Updated: 2025/04/29 10:33:11 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int file)
{
	static t_buffer	b;
	char			*line;
	size_t			length;

	length = 1;
	line = NULL;
	b.file = file;
	while (length > 0 && !ft_strchr(line, '\n'))
	{
		length = read_buffer(&b);
		line = append(line, b.data + b.head, length);
		b.head += length;
	}
	return (line);
}
