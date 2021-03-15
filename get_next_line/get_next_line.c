#include "get_next_line.h"

int get_next_line (int fd, char **line)
{
	static char *store[MAX_LIMIT];
	char buf[BUFFER_SIZE + 1];
	int  bytesread;
	char *newline;
	char *tmp;

	if (!line || BUFFER_SIZE <= 0)
		return (-1);
		
	while (line && ((bytesread = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		if (!store[fd])
			store[fd] = ft_strnew(1);
		buf[bytesread] = '\0';
		tmp = ft_strjoin(store[fd], buf);
		ft_strdel(&store[fd]);
		store[fd] = tmp;
		if ((newline = ft_strchr(store[fd], '\n')))
			break;
	}

	if (bytesread < 0 || fd < 0 || fd == 1 || fd == 2 || fd >= MAX_LIMIT)
		return (-1);

	if (!bytesread && (store[fd] == NULL || *store[fd] == '\0'))
	{
		ft_strdel(&store[fd]);
		return (0);
	}
	
	while ((newline = ft_strchr(store[fd], '\n')))
	{
		*newline++ = '\0';
		*line = ft_strdup(store[fd]);
		tmp = ft_strdup(newline);
		ft_strdel(&store[fd]);
		store[fd] = tmp;
		return (1);
	}
	*line = ft_strdup(store[fd]);
	ft_strdel(&store[fd]);
	return (1);
}

//int main (void)
//{
//	int 	fd;
//	char	*line;
//
//	fd = open("42_no_nl.txt", O_RDWR);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//	return (0);
//}