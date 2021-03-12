#include "get_next_line.h"

int get_next_line (int fd, char **line)
{
	int BUFFER_SIZE = 10;
	static char *store[1024];
	char buf[BUFFER_SIZE + 1];
	int bytes_read;
	char *tmp;
	static char *buf_tmp;
	char extra[BUFFER_SIZE + 1];
	int i;
	int j;

	//printf("buf_tmp: %s\n", buf_tmp);
	if (fd < 0 || line == NULL)
		return (-1);
	if (store[fd] != NULL && i > 0)
		ft_strdel(&store[fd]);

	if (buf_tmp != NULL)
		store[fd] = ft_strdup(buf_tmp);

	while (!(ft_strchr(buf, '\n')))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		if (store[fd] == NULL)
		{
			store[fd] = ft_strdup(buf);
		}
		else if (!(ft_strchr(buf, '\n')))
		{
			tmp = ft_strjoin(store[fd], buf);
			ft_strdel(&store[fd]);
			store[fd] = tmp;
		}
		else
		{
			i = 0;
			buf_tmp = malloc(sizeof(char) * BUFFER_SIZE);
			while (buf[i] != '\n')
			{
				extra[i] = buf[i];
				i++;
			}  
			extra[++i] = '\0';
			j = 0;
			while (i < BUFFER_SIZE)
			{
				buf_tmp[j++] = buf[i++];
			}
			buf_tmp[j] = '\0';
			tmp = extra;
			store[fd] = ft_strjoin(store[fd], tmp);		
		}
	}
	if (line == NULL && (store[fd] == NULL && bytes_read == 0 && buf == 0))
		return (0);
	*line = store[fd];
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
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
}