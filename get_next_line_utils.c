/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 23:26:32 by hroh              #+#    #+#             */
/*   Updated: 2020/10/26 18:19:52 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t s;

	s = 0;
	while (str[s] != 0)
		s++;
	return (s);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t s;
	size_t src_len;

	s = 0;
	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[s] && s < size - 1)
	{
		dest[s] = src[s];
		s++;
	}
	dest[s] = 0;
	return (src_len);
}

char	*ft_strdup(const char *str)
{
	char	*re;
	size_t	len;

	len = ft_strlen(str);
	if (!(re = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(re, str, len + 1);
	return (re);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*re;
	size_t	s1_len;
	size_t	s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(re = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_strlcpy(re, s1, s1_len + 1);
	ft_strlcpy(re + s1_len, s2, s2_len + 1);
	return (re);
}
