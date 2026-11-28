/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose-al <ajose-al@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:47:41 by ajose-al          #+#    #+#             */
/*   Updated: 2026/11/28 00:26:33 by ajose-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

long	get_read_size(char *buffer, int fd)
{
	if (fd < 0)
		return (-1);
	if (*buffer)
		return (get_len(buffer, NULL_CHAR));
	return (read(fd, buffer, BUFFER_SIZE));
}

size_t	get_len(char *buffer, char terminator)
{
	size_t		i;

	i = 0;
	while (buffer[i])
		if (buffer[i++] == terminator)
			return (i);
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (!size)
		return (src_len);
	i = 0;
	while (i < size - 1 && i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strnjoinfree(char const *s1, char const *s2, size_t s1l, size_t s2l)
{
	char	*join;

	if (!s2)
		return (NULL);
	join = malloc(s1l + s2l + 1 * sizeof(char));
	if (!join)
	{
		if (s1)
			free((char *)s1);
		return (NULL);
	}
	if (s1)
	{
		ft_strlcpy(join, s1, s1l + 1);
		free((char *)s1);
	}
	ft_strlcpy(join + s1l, s2, s2l + 1);
	return (join);
}

void	shift(char *buffer, size_t linelen, size_t rsize)
{
	size_t	i;

	i = 0;
	while (linelen < rsize)
	{
		buffer[i] = buffer[linelen];
		linelen++;
		i++;
	}
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
}
