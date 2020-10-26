/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 23:26:37 by hroh              #+#    #+#             */
/*   Updated: 2020/10/26 19:47:54 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

# include <unistd.h>
# include <stdlib.h>

int get_next_line(int fd, char **line);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
