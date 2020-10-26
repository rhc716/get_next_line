/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 23:26:29 by hroh              #+#    #+#             */
/*   Updated: 2020/10/26 19:40:40 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	assign_next_line(char **appended, char **line, int n_pos)
{
	char	*temp;

	(*appended)[n_pos] = 0;
	*line = ft_strdup(*appended);
	if (ft_strlen(*appended + n_pos + 1) == 0)
	{
		free(*appended);
		*appended = 0;
	}
	else
	{
		temp = ft_strdup(*appended + n_pos + 1);
		free(*appended);
		*appended = temp;
	}
}

static int	check_newline(char *appended)
{
	int i;

	i = 0;
	while (appended[i])
	{
		if (appended[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	return_value(int read_i, char **appended, char **line)
{
	int				n_pos;

	if (read_i < 0)
		return (-1);
	else if (*appended && (n_pos = check_newline(*appended)) >= 0)
	{
		assign_next_line(appended, line, n_pos);
		return (1);
	}
	else
	{
		*line = *appended;
		*appended = 0;
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	static char		*appended[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	int				read_i;
	int				n_pos;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_i] = 0;
		appended[fd] = ft_strjoin(appended[fd], buf);
		if ((n_pos = check_newline(appended[fd])) >= 0)
		{
			assign_next_line(&appended[fd], line, n_pos);
			return (1);
		}
	}
	return (return_value(read_i, &appended[fd], line));
}
