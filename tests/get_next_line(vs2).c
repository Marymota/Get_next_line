#include "get_next_line.h"

int get_next_line (int fd, char **line)
{
	int BUFFER_SIZE = 100;
	static char *store[1024];
	char buf[BUFFER_SIZE + 1];
	int bytes_read;
	char *tmp;
	static char *buf_tmp;
	char extra[BUFFER_SIZE + 1];
	int i;
	int j;

	printf("###################### %s\n", buf);
	if (fd < 0 || line == NULL)
		return (-1);

	if (store[fd] != NULL && i > 0)
		free(store[fd]);

	if (buf_tmp != NULL)
		store[fd] = ft_strdup(buf_tmp);
	
	while (bytes_read && !(ft_strchr(buf, '\n')))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (!bytes_read && buf_tmp == NULL)
		{
			free(store[fd]);
			ft_strdel(line);
			printf("return 0");
			return (0);
		}
		buf[bytes_read] = '\0';
		if (store[fd] == NULL && bytes_read)
			store[fd] = ft_strdup(buf);
		else if (!(ft_strchr(buf, '\n')) && bytes_read)
		{
			tmp = ft_strjoin(store[fd], buf);
			free(store[fd]);
			store[fd] = tmp;
		}
		else if (!(ft_strchr(buf, '\n')) && buf_tmp != NULL)
			store[fd] = ft_strdup(buf_tmp);
		else
		{
			i = 0;
			buf_tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE);
			while (buf[i] != '\n')
			{
				extra[i] = buf[i];
				i++;
			}  
			extra[i++] = '\0';
			j = 0;
			while (i < BUFFER_SIZE)
				buf_tmp[j++] = buf[i++];
			buf_tmp[j] = '\0';
			tmp = extra;
			store[fd] = ft_strjoin(store[fd], tmp);		
		}		
		
		*line = store[fd];
	}
	while (store[fd] == NULL && buf_tmp != NULL)
	{
		store[fd] = ft_strdup(buf_tmp);
	}
	return (1);
}

int main (void)
{
	int 	fd;
	char	*line;
	int ret;

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
	//while ((ret = get_next_line(fd, &line)) == 1)
	//{
	//	printf("%s\n", line);
	//}
	return (0);
}