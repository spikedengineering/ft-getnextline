/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose-al <ajose-al@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:13:21 by ajose-al          #+#    #+#             */
/*   Updated: 2026/11/24 12:21:52 by ajose-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_len(char *buffer, char separator)
{
	size_t		i;

	i = 0;
	while (buffer[i])
		if (buffer[i++] == separator)
			return (i);
	return (i);
}

static size_t	get_read_size(char *buffer, int fd)
{
	if (*buffer)
		return (get_len(buffer, '\0'));
	return (read(fd, buffer, BUFFER_SIZE));
}

void	shift_left_overs(char *buffer, size_t linelen, size_t rsize)
{
	size_t	i;

	i = 0;
	while (linelen < rsize)
	{
		buffer[i] = buffer[linelen];
		linelen++;
		i++;
	}
	buffer[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char			buffer[BUFFER_SIZE + 1];
	t_read_data			data;

	data.plinelen = 0;
	data.alloc = 2;
	data.str = NULL;
	while (1)
	{
		data.readsize = get_read_size(buffer, fd);
		if (data.readsize <= 0)
			return (NULL);
		data.linelen = get_len(buffer, NEW_LINE_CHAR);
		data.str = realloc_str(data, buffer, &data.alloc);
		if (!data.str)
			return (NULL);
		if (buffer[data.linelen - 1] == NEW_LINE_CHAR)
		{
			shift_left_overs(buffer, data.linelen, data.readsize);
			return (strncut(data.str, data.plinelen + data.linelen));
		}
		shift_left_overs(buffer, data.linelen, data.readsize);
		data.plinelen += data.linelen;
	}
}

//#include <stdio.h>
//#include <fcntl.h>
//int	main(void)
//{
//	int		fd;
//	char	*str;
//	size_t	i;
//	size_t	repeat;
//
//	fd = open("loremipsum.txt", O_RDONLY);
//	if (fd < 0)
//		return (0);
//	repeat = 9;
//	i = 0;
//	while (i < repeat)
//	{
//		str = get_next_line(fd);
//		printf("%s", str);
//		free(str);
//		i++;
//	}
//	close(fd);
//	printf("[LOG] Tried to get (%zu) lines out of fd (%d).\n", repeat, fd);
//	return (0);
//}
