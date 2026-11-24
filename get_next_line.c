/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose-al <ajose-al@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:13:21 by ajose-al          #+#    #+#             */
/*   Updated: 2026/11/24 07:03:17 by ajose-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static unsigned int	get_read_size(char *buffer, int fd)
{
	if (*buffer)
		return (ft_strlen(buffer));
	return (read(fd, buffer, BUFFER_SIZE));
}

static unsigned int	get_line_len(char *buffer)
{
	unsigned int		i;

	i = 0;
	while (buffer[i])
		if (buffer[i++] == '\n')
			return (i);
	return (i);
}

void	shift_left_overs(char *buffer, unsigned int linelen, unsigned int rsize)
{
	unsigned int	i;

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

	data.str = NULL;
	while (1)
	{
		data.readsize = get_read_size(buffer, fd);
		if (data.readsize <= 0)
			return (NULL);
		data.linelen = get_line_len(buffer);
		data.str = ft_strnjoin(data.str, buffer, data.linelen);
		if (!data.str)
			return (NULL);
		if (buffer[data.linelen - 1] == '\n')
		{
			shift_left_overs(buffer, data.linelen, data.readsize);
			return (data.str);
		}
		shift_left_overs(buffer, data.linelen, data.readsize);
	}
}

//#include <fcntl.h>
//int	main(void)
//{
//	int				fd;
//	char			*str;
//	unsigned int	i;
//	unsigned int	repeat;
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
//	printf("[LOG] Tried to get (%d) lines out of fd (%d).\n", repeat, fd);
//	return (0);
//}
