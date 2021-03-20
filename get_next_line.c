/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:33:22 by marmota           #+#    #+#             */
/*   Updated: 2021/03/20 22:34:11 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	display_newline(int fd, char **line, char **store)
{
	char	*tmp;
	char	*newline;

	newline = ft_strchr(store[fd], '\n');
	*newline++ = '\0';
	*line = ft_strdup(store[fd]);
	tmp = ft_strdup(newline);
	free(store[fd]);
	store[fd] = tmp;
	return (1);
}

static int	get_newline(int fd, char *buf, char **store)
{
	char	*tmp;

	if (store[fd])
	{
		tmp = ft_strjoin(store[fd], buf);
		ft_strdel(&store[fd]);
		store[fd] = tmp;
	}
	else
		store[fd] = ft_strdup(buf);
	if (ft_strchr(store[fd], '\n'))
		return (1);
	return (0);
}

int	get_next_line (int fd, char **line)
{
	static char	*store[4096];
	char		*buf;
	int			bytesread;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytesread = read(fd, buf, BUFFER_SIZE);
	while (bytesread > 0)
	{
		buf[bytesread] = '\0';
		if (get_newline(fd, buf, store))
			break ;
		bytesread = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytesread < 0 || fd < 0 || fd >= 4096)
		return (-1);
	else if (!bytesread && store[fd] == NULL)
		*line = ft_strdup("");
	else if (!ft_strchr(store[fd], '\n'))
		*line = ft_strdup(store[fd]);
	else
		return (display_newline(fd, line, store));
	ft_strdel(&store[fd]);
	return (0);
}
