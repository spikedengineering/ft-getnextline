/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose-al <ajose-al@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:13:21 by ajose-al          #+#    #+#             */
/*   Updated: 2026/11/24 12:21:35 by ajose-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

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
		return (get_len(buffer, NULL_CHAR));
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
	buffer[i] = NULL_CHAR;
}

char	*alloc_left_overs(t_read_data d, char *buffer, size_t rsize)
{
	size_t	i;
	char	*str;

	if (d.leftovers)
	{
		free(d.leftovers);
		d.leftovers = NULL;
	}
	str = malloc((get_len(buffer + d.linelen, NULL_CHAR) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (d.linelen < rsize)
	{
		str[i] = buffer[d.linelen];
		d.linelen++;
		i++;
	}
	str[i] = NULL_CHAR;
	return (str);
}

char	*get_next_line(int fd)
{
	static t_read_data	dat[MAX_FDS];
	char				buffer[BUFFER_SIZE + 1];
	size_t				iterator;
	size_t				i;

	iterator = 0;
	dat[fd].plinelen = 0;
	dat[fd].alloc = 2;
	dat[fd].str = NULL;
	i = 0;
	if (fd == -1)
	{
		while (i < MAX_FDS)
		{
			if (dat[i].leftovers)
			{
				free(dat[i].leftovers);
				dat[i].leftovers = NULL;
			}
			i++;
		}
		return (NULL);
	}
	if (dat[fd].leftovers)
	{
		while (dat[fd].leftovers[i])
		{
			buffer[i] = dat[fd].leftovers[i];
			i++;
		}
		buffer[i] = NULL_CHAR;
		free(dat[fd].leftovers);
		dat[fd].leftovers = NULL;
	}
	while (1)
	{
		dat[fd].readsize = get_read_size(buffer, fd);
		if (dat[fd].readsize <= 0)
			return (NULL);
		dat[fd].linelen = get_len(buffer, NEW_LINE_CHAR);
		dat[fd].str = realloc_str(dat[fd], buffer, &dat[fd].alloc);
		if (!dat[fd].str)
			return (NULL);
		if (buffer[dat[fd].linelen - 1] == NEW_LINE_CHAR)
		{
			dat[fd].leftovers = alloc_left_overs(dat[fd], buffer,
					dat[fd].readsize);
			return (strncut(dat[fd].str, dat[fd].plinelen + dat[fd].linelen));
		}
		shift_left_overs(buffer, dat[fd].linelen, dat[fd].readsize);
		dat[fd].plinelen += dat[fd].linelen;
		iterator++;
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
//	fd = open("longline.txt", O_RDONLY);
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
//	get_next_line(-1);
//	close(fd);
//	printf("[LOG] Tried to get (%zu) lines out of fd (%d).\n", repeat, fd);
//	return (0);
//}
