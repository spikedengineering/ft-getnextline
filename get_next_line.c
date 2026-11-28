/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose-al <ajose-al@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:13:21 by ajose-al          #+#    #+#             */
/*   Updated: 2026/11/28 00:35:33 by ajose-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	t_read_data	data;

	data.pllen = 0;
	data.str = NULL;
	while (1)
	{
		data.readsize = get_read_size(buffer, fd);
		if (data.readsize < 0)
		{
			if (data.str)
				free(data.str);
			return (NULL);
		}
		if (data.readsize == 0 && !*buffer && !data.str)
			return (NULL);
		data.llen = get_len(buffer, BL_CHAR);
		data.str = ft_strnjoinfree(data.str, buffer, data.pllen, data.llen);
		if (!data.str)
			return (NULL);
		data.pllen += data.llen;
		if (buffer[data.llen - 1] == BL_CHAR || (!*buffer && data.str))
			return (shift(buffer, data.llen, data.readsize), data.str);
		shift(buffer, data.llen, data.readsize);
	}
}

//#include <stdio.h>
//#include <fcntl.h>
//int	main(int argc, char **argv)
//{
//	int		fd;
//	char	*str;
//	size_t	i;
//	size_t	repeat_max;
//	char	file[] = "get_next_line.c";
//	char	*pfile;
//
//	if (argc > 1)
//		pfile = argv[1];
//	else
//		pfile = file;
//
//	fd = open(pfile, O_RDONLY);
//	if (fd < 0)
//		return (0);
//	repeat_max = 999;
//	i = 0;
//	while (i < repeat_max)
//	{
//		str = get_next_line(fd);
//		if (!str)
//		{
//			free(str);
//			break ;
//		}
//		printf("%s", str);
//		free(str);
//		i++;
//	}
//	close(fd);
//	printf("-\n[LOG] Got (%zu) lines out of fd (%d).\n", i, fd);
//	return (0);
//}
