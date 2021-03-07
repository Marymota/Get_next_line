#include "get_next_line.h"

void	line_ret(char *nl, char **s, int f, char **l)
{
	char	*t;

	if (!(nl = ft_strchr(s[f], '\n')))
	{
		*l = ft_strdup(s[f]);
		ft_strdel(&s[f]);
	}
	else
	{
		*nl++ = '\0';
		*l = ft_strdup(s[f]);
		t = ft_strdup(nl);
		ft_strdel(&s[f]);
		s[f] = t;
	}
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*store[65535];
	char			*temp;
	char			*nl;
	int				n;

	while (line && fd >= 0 && ((n = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		!store[fd] ? store[fd] = ft_strnew(1) : 0;
		buf[n] = '\0';
		temp = ft_strjoin(store[fd], buf);
		ft_strdel(&store[fd]);
		store[fd] = temp;
		if ((nl = ft_strchr(store[fd], '\n')))
			break ;
	}
	if (n < 0 || fd < 0 || line == NULL)
		return (-1);
	else if (!n && (store[fd] == NULL || *store[fd] == '\0'))
	{
		ft_strdel(&store[fd]);
		return (0);
	}
	line_ret(nl, store, fd, line);
	return (1);
}
 
//int 	main(void)
//{
//	char 	*line;
//	int 	fd;
//
//	fd = open("text.txt", O_RDONLY);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
//}