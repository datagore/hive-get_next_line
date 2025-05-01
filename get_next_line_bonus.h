/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostrom <abostrom@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:59:56 by abostrom          #+#    #+#             */
/*   Updated: 2025/05/01 13:08:44 by abostrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef MAX_FILES
#  define MAX_FILES 50
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct buffer
{
	char			data[BUFFER_SIZE + 1];
	ssize_t			head;
	ssize_t			tail;
	int				file;
	struct buffer	*next;
}	t_buffer;

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int chr);
void	*ft_memcpy(void *dst, const void *src, size_t len);
char	*append(char *target, const char *source, ssize_t source_length);
size_t	read_buffer(t_buffer *buffer);

#endif
