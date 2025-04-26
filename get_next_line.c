/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:36:36 by abostrom          #+#    #+#             */
/*   Updated: 2025/04/26 17:53:50 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_memchr(const void *data, int value, size_t length)
{
	const unsigned char	*bytes;

	bytes = (const unsigned char *) data;
	while (length-- > 0)
		if (*bytes++ == (unsigned char) value)
			return ((char *) bytes - 1);
	return (NULL);
}

static size_t	ft_strlen(const char *string)
{
	if (string == NULL)
		return (0);
	return (ft_memchr(string, '\0', SIZE_MAX) - string);
}

static void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	while (len-- > 0)
		*((unsigned char *) dst + len) = *((unsigned char *) src + len);
	return (dst);
}

static char	*append(char *target, const char *source, size_t source_length)
{
	const size_t	target_length = ft_strlen(target);
	char *const		string = malloc(target_length + source_length + 1);

	if (string != NULL)
	{
		ft_memcpy(string, target, target_length);
		ft_memcpy(string + target_length, source, source_length);
		string[target_length + source_length] = '\0';
	}
	free(target);
	return (string);
}

char	*get_next_line(int file)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	begin;
	static ssize_t	end;
	char			*line;
	char			*newline;

	line = NULL;
	while (1)
	{
		newline = ft_memchr(buffer + begin, '\n', end - begin);
		if (newline != NULL)
		{
			line = append(line, buffer + begin, newline - buffer - begin + 1);
			begin = newline - buffer + 1;
			return (line);
		}
		if (begin < end)
			line = append(line, buffer + begin, end - begin);
		begin = 0;
		end = read(file, buffer, BUFFER_SIZE);
		if (end == 0)
			return (line);
		if (end < 0)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}
