/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose-al <ajose-al@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:13:21 by ajose-al          #+#    #+#             */
/*   Updated: 2026/11/23 06:04:36 by ajose-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int	get_line_len(char *buffer)
{
	unsigned int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static char	*get_prev_str(char *str, char *leftovers)
{
	if (str)
		return (str);
	else if (leftovers)
		return (leftovers);
	else
		return (NULL);
}

static char	*get_left_overs(unsigned int readsize, unsigned int i, char *buffer)
{
	if (i + 1 < readsize)
	{
		if (buffer[i] == '\n')
			return (ft_strdup(buffer + i + 1));
		else
			return (ft_strdup(buffer + i));
	}
	return (NULL);
}

static unsigned int	get_read_size(char *leftovers, char *buffer, int fd)
{
	if (leftovers)
	{
		ft_strlcpy(buffer, leftovers, BUFFER_SIZE);
		return (ft_strlen(leftovers) + 1);
	}
	return (read(fd, buffer, BUFFER_SIZE));
}

char	*get_next_line(int fd)
{
	static char			*leftovers;
	static char			buffer[BUFFER_SIZE + 1];
	t_read_data			data;

	data.prevstr = NULL;
	data.str = NULL;
	while (1)
	{
		data.readsize = get_read_size(leftovers, buffer, fd);
		if (data.readsize <= 0)
			return (NULL);
		data.i = get_line_len(buffer);
		if (leftovers)
		{
			free(leftovers);
			leftovers = NULL;
		}
		data.prevstr = get_prev_str(data.str, leftovers);
		data.str = ft_strjoin(data.prevstr, buffer, data.i + 1);
		if (!data.str)
			return (NULL);
		leftovers = get_left_overs(data.readsize, data.i, buffer);
		if (buffer[data.i] == '\n')
			return (data.str);
	}
}

//#include <fcntl.h>
//#include <stdio.h>
//int	main(void)
//{
//	int		fd;
//	char	*str;
//
//	fd = open("loremipsum.txt", O_RDONLY);
//	if (fd < 0)
//		return (0);
//	str = get_next_line(fd);
//	printf("%s", str);
//	free(str);
//	str = get_next_line(fd);
//	printf("%s", str);
//	free(str);
//	str = get_next_line(fd);
//	printf("%s", str);
//	free(str);
//	str = get_next_line(fd);
//	printf("%s", str);
//	free(str);
//	str = get_next_line(fd);
//	printf("%s", str);
//	free(str);
//	str = get_next_line(fd);
//	printf("%s", str);
//	free(str);
//	return (0);
//}
