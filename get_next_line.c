/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:36:36 by abostrom          #+#    #+#             */
/*   Updated: 2025/04/21 17:44:17 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *target, const void *source, size_t length)
{
	while (length-- > 0)
		*((char*) target + length) = *((char*) source + length);
}

static void	*grow_buffer(char *old_data, size_t old_size)
{
	void	*new_data;

	new_data = malloc(old_size * 2);
	if (new_data != NULL)
		ft_memcpy(new_data, old_data, old_size);
	free(old_data);
	return (new_data);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		received;
	size_t		length;
	size_t		max_length;

	length = 0;
	max_length = BUFFER_SIZE;
	buffer = malloc(max_length);
	received = 1;
	while (received > 0)
	{
		received = read(fd, buffer + length, BUFFER_SIZE);
		if (received == -1)
		{
			free(string);
			return (NULL);
		}
		length += received;
	}
	return (string);
}
