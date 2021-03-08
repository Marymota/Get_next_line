#include "get_next_line.h"

int get_next_line (int fd, char **line)
{
	int BUFFER_SIZE = 5;
	static char *store[50000];
	char buf[BUFFER_SIZE + 1];
	int byte_read;
	char *read_bits;
	char *tmp;
	char **buf_tmp;
	int len;
	int surplus;

	tmp = "\0";
	while (!(ft_strchr(buf, '\n')))
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		printf("Buf: %s\n\n",   buf);
		buf[byte_read] = '\0';
		buf_tmp = ft_split(buf, '\n');
		tmp = ft_strjoin(tmp, *buf_tmp);
		store[fd] = tmp;
		*line = ft_strdup(store[fd]);
		//printf("Store[fd]: %s\n\n",   store[fd]);
	}
	ft_strdel(&store[fd]);
	return (1);
}

int main (void)
{
	int 	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
}