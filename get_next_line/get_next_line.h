/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:09:10 by cvine             #+#    #+#             */
/*   Updated: 2022/01/02 22:56:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2048
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*find_newline(const char *s);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize);
char	*ft_strdup(const char *s1);
char	*gnl_strjoin(char const *s1, char const *s2);

#endif