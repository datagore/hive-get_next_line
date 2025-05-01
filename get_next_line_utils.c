/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:36:04 by abostrom          #+#    #+#             */
/*   Updated: 2025/05/01 13:00:31 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int chr)
{
	while (str && (*str != '\0' || chr == '\0'))
		if (*str++ == (unsigned char) chr)
			return ((char *) str - 1);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	while (len-- > 0)
		*((unsigned char *) dst + len) = *((unsigned char *) src + len);
	return (dst);
}

char	*append(char *dst, const char *src, ssize_t src_length)
{
	size_t	dst_length;
	char	*string;

	if (src_length <= 0)
		return (dst);
	dst_length = ft_strchr(dst, '\0') - dst;
	string = malloc(dst_length + src_length + 1);
	if (string)
	{
		ft_memcpy(string, dst, dst_length);
		ft_memcpy(string + dst_length, src, src_length);
		string[dst_length + src_length] = '\0';
	}
	free(dst);
	return (string);
}

size_t	read_buffer(t_buffer *buf)
{
	char	*end;

	if (buf->tail <= buf->head)
	{
		buf->head = 0;
		buf->tail = read(buf->file, buf->data + buf->head, BUFFER_SIZE);
		if (buf->tail <= 0)
			return (0);
		buf->data[buf->tail] = '\0';
	}
	end = ft_strchr(buf->data + buf->head, '\n');
	if (end == NULL)
		return (buf->tail - buf->head);
	return (end + 1 - (buf->data + buf->head));
}
