/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:36:36 by abostrom          #+#    #+#             */
/*   Updated: 2025/04/22 17:18:50 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "get_next_line.h"

static void	*ft_memchr(const void *data, int value, size_t size)
{
	const unsigned char	*byte;
	const unsigned char	*end;

	byte = (const unsigned char*) data;
	end = byte + size;
	while (byte != end)
		if (*byte++ == (unsigned char) value)
			return ((void*) byte);
	return (NULL);
}

static size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	while (string != NULL && string[length] != '\0')
		length++;
	return (length);
}

static void*	ft_memcpy(void *target, const void *source, size_t length)
{
	char		*target_bytes;
	const char	*source_bytes;
	size_t		index;

	if (target != NULL && source != NULL)
	{
		target_bytes = (char*) target;
		source_bytes = (const char*) source;
		index = 0;
		while (index < length)
		{
			target_bytes[index] = source_bytes[index];
			index++;
		}
	}
	return (target);
}

static char	*join(char *a, const char *b, size_t b_length)
{
	size_t a_length = ft_strlen(a);
	char *string = malloc(a_length + b_length + 1);
	if (string != NULL)
	{
		ft_memcpy(string, a, a_length);
		ft_memcpy(string + a_length, b, b_length);
		string[a_length + b_length] = '\0';
	}
	free(a);
	return (string);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static size_t	saved;
	char	*line = NULL;
	char	*newline;
	if (saved > 0)
	{
		line = join(line, buffer, saved);
		saved = 0;
	}
	ssize_t received = 1;
	while (received > 0)
	{
		received = read(fd, buffer, BUFFER_SIZE);
		if (received < 0)
		{
			free(line);
			return (NULL);
		}
		if (received > 0)
		{
			newline = ft_memchr(buffer, '\n', received);
			if (newline != NULL)
			{
				saved = received - (newline - buffer);
				line = join(line, buffer, newline - buffer);
				memmove(buffer, newline, saved);
				break ;
			}
			line = join(line, buffer, received);
		}
	}
	return (line);
}
