#include "get_next_line.h"


char *check_remainder(char *remainder, char **line)
{
	char *p_n;

	p_n = NULL;
	if (remainder)
	{
		if (p_n = ft_strchr(remainder, '\n'))
		{
			p_n = '\0';
			*line = ft_strdup(remainder);
		}
	}
	else
	{
		*line = strnew(1);
	}
}

int		get_next_line(int fd, char **line)// 1, 0, -1
{
	char buf[1000 + 1];
	int	byte_read;
	char *p_n;
	int	flag;
	static char *remainder;

	flag = 1;
	if (remainder)
		* line = ft_strdup(remainder);
	else
		*line = strnew(1);
	while (flag && (byte_read = read(fd, buf, 1000)))
	{
		buf[byte_read] = '\0';
		if (p_n = ft_strchr(buf, '\n'))
		{
			*p_n = '\0';
			flag = 0;
			p_n++;
			remainder = ft_strdup(p_n);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int 	main(void)
{
	char 	*line;
	int 	fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
}