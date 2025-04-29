/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:36:04 by abostrom          #+#    #+#             */
/*   Updated: 2025/04/29 12:37:11 by abostrom         ###   ########.fr       */
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

size_t	read_buffer(t_buffer *b)
{
	char	*end;

	if (b->tail <= b->head)
	{
		b->head = 0;
		b->tail = read(b->file, b->data + b->head, BUFFER_SIZE);
		if (b->tail <= 0)
			return (0);
		b->data[b->tail] = '\0';
	}
	end = ft_strchr(b->data + b->head, '\n');
	if (end == NULL)
		return (b->tail - b->head);
	return (end + 1 - (b->data + b->head));
}
