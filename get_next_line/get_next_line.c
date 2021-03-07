#include "get_next_line.h"

int get_next_line (int fd, char **line)
{
	int BUFFER_SIZE = 5;
	static char *store[255]; //
	char buf[BUFFER_SIZE + 1];
	int byte_read;
	char *read_bits;
	char *new_line;
	char **buf_tmp;


	new_line = "\0";
	while (!(ft_strchr(buf, '\n')))
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		buf_tmp = ft_split(buf, '\n');
		new_line = ft_strjoin(new_line, *buf_tmp);
	}
	return (1);
}

int main (void)
{
	int 	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
}