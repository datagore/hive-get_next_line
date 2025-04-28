/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:42:53 by abostrom          #+#    #+#             */
/*   Updated: 2025/04/28 15:00:22 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct buffer
{
	char			data[BUFFER_SIZE + 1];
	char			*start;
	ssize_t			length;
	int				file;
	struct buffer	*next;
}	t_buffer;

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int chr);
void	*ft_memcpy(void *dst, const void *src, size_t len);
char	*append(char *target, const char *source, size_t source_length);
size_t	read_buffer(t_buffer *buffer);

#endif
