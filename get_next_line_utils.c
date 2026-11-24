/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose-al <ajose-al@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:47:41 by ajose-al          #+#    #+#             */
/*   Updated: 2026/11/24 10:20:10 by ajose-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*realloc_and_free_str(t_read_data data, char *buffer, size_t *alloc)
{
	size_t	i;
	size_t	ii;
	char	*newstr;

	i = 0;
	newstr = malloc((*alloc + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (i < data.plinelen)
	{
		newstr[i] = data.str[i];
		i++;
	}
	ii = 0;
	while (ii < data.linelen)
	{
		newstr[i] = buffer[ii];
		i++;
		ii++;
	}
	newstr[i] = '\0';
	free(data.str);
	return (newstr);
}

static char	*append_str(t_read_data data, char *buffer)
{
	size_t	i;
	size_t	ii;

	i = 0;
	ii = data.plinelen;
	while (i < data.linelen)
	{
		data.str[ii] = buffer[i];
		i++;
		ii++;
	}
	data.str[ii] = '\0';
	return (data.str);
}

static char	*alloc_str(t_read_data data, char *buffer, size_t *alloc)
{
	size_t	i;

	i = 0;
	data.str = malloc((*alloc + 1) * sizeof(char));
	if (!data.str)
		return (NULL);
	while (i < data.linelen)
	{
		data.str[i] = buffer[i];
		i++;
	}
	data.str[i] = '\0';
	return (data.str);
}

char	*realloc_str(t_read_data data, char *buffer, size_t *alloc)
{
	size_t	palloc;
	size_t	i;

	palloc = *alloc;
	while (*alloc <= data.linelen + data.plinelen)
		(*alloc) *= 2;
	i = 0;
	if (!data.str)
		return (alloc_str(data, buffer, alloc));
	else
	{
		if (*alloc > palloc)
			return (realloc_and_free_str(data, buffer, alloc));
		else
			return (append_str(data, buffer));
	}
}

char	*strncut(char *str, size_t n)
{
	char	*newstr;
	size_t	i;

	newstr = malloc((n + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < n)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	free(str);
	return (newstr);
}
