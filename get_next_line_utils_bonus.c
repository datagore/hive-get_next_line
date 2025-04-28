/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:01:43 by abostrom          #+#    #+#             */
/*   Updated: 2025/04/28 15:01:48 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int chr)
{
	if (str != NULL)
		while (*str != '\0' || chr == '\0')
			if (*str++ == (unsigned char)chr)
				return ((char *)str - 1);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	while (len-- > 0)
		*((unsigned char *) dst + len) = *((unsigned char *) src + len);
	return (dst);
}

char	*append(char *target, const char *source, size_t source_length)
{
	size_t	target_length;
	char	*string;

	if (source_length == 0)
		return (target);
	target_length = ft_strchr(target, '\0') - target;
	string = malloc(target_length + source_length + 1);
	if (string != NULL)
	{
		ft_memcpy(string, target, target_length);
		ft_memcpy(string + target_length, source, source_length);
		string[target_length + source_length] = '\0';
	}
	free(target);
	return (string);
}

size_t	read_buffer(t_buffer *buffer)
{
	char	*end;

	if (buffer->length <= 0)
	{
		buffer->start = buffer->data;
		buffer->length = read(buffer->file, buffer->data, BUFFER_SIZE);
		if (buffer->length <= 0)
			return (0);
		buffer->data[buffer->length] = '\0';
	}
	end = ft_strchr(buffer->start, '\n');
	if (end == NULL)
		return (buffer->length);
	return (end + 1 - buffer->start);
}
