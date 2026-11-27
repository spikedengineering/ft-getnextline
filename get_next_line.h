/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose-al <ajose-al@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:08:16 by ajose-al          #+#    #+#             */
/*   Updated: 2026/11/27 17:29:20 by ajose-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef BL_CHAR
#  define BL_CHAR '\n'
# endif

# ifndef NULL_CHAR
#  define NULL_CHAR '\0'
# endif

typedef struct s_read_data
{
	long	readsize;
	size_t	llen;
	size_t	pllen;
	char	*str;
}	t_read_data;

long	get_read_size(char *buffer, int fd);
size_t	get_len(char *s, char terminator);
char	*ft_strnjoinfree(char const *s1, char const *s2,
			size_t s1l, size_t s2l);
void	shift(char *buffer, size_t llen, size_t rsize);

char	*get_next_line(int fd);

#endif
