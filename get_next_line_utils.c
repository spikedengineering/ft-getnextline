/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajose-al <ajose-al@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:47:41 by ajose-al          #+#    #+#             */
/*   Updated: 2026/11/23 05:22:49 by ajose-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_alloc;
	void	*alloc;
	size_t	i;

	total_alloc = nmemb * size;
	if ((nmemb && total_alloc / nmemb != size) || total_alloc < 0)
		return (NULL);
	alloc = malloc(total_alloc);
	if (!alloc)
		return (NULL);
	if (total_alloc > 0)
	{
		i = 0;
		while (i < total_alloc)
		{
			((unsigned char *)alloc)[i] = (unsigned char) '\0';
			i++;
		}
	}
	return (alloc);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t s2_len)
{
	size_t	s1_len;
	char	*join;

	if (!s2)
		return (NULL);
	if (s1)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	join = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!join)
		return (NULL);
	if (s1)
		ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy(join + s1_len, s2, s2_len + 1);
	return (join);
}

char	*ft_strdup(const char *s)
{
	int		str_len;
	int		i;
	char	*dup;

	str_len = ft_strlen(s);
	dup = malloc((str_len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
