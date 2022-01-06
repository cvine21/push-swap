/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:13:47 by cvine             #+#    #+#             */
/*   Updated: 2021/11/12 18:03:28 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_newline(const char *s)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t	dstsize)
{
	size_t	i;

	i = 0;
	if ((src[i] || dst[i]) && dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;

	len = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s1, len + 1);
	return (cpy);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	bufsize;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	bufsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	joint = (char *)malloc(sizeof(char) * bufsize);
	if (!joint)
		return (NULL);
	i = -1;
	while (s1[++i])
		joint[i] = s1[i];
	j = -1;
	while (s2[++j])
		joint[i + j] = s2[j];
	joint[i + j] = '\0';
	free((char *)s1);
	return (joint);
}
