/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose-al <ajose-al@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:08:16 by ajose-al          #+#    #+#             */
/*   Updated: 2026/11/24 09:19:42 by ajose-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef NEW_LINE_CHAR
#  define NEW_LINE_CHAR '\n'
# endif

typedef struct s_read_data
{
	size_t	readsize;
	size_t	linelen;
	size_t	plinelen;
	size_t	alloc;
	char	*str;
}	t_read_data;

char	*realloc_str(t_read_data data, char *buffer, size_t *alloc);
char	*strncut(char *str, size_t n);

char	*get_next_line(int fd);

#endif
