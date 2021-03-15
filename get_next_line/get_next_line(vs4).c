#include "get_next_line.h"

int get_next_line (int fd, char **line)
{
	
}

int main (void)
{
	int 	fd;
	char	*line;
	int ret;

	fd = open("text.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%s\n", line);
	}
	return (0);
}