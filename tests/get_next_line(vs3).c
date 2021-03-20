#include "get_next_line.h"

int get_next_line (int fd, char **line)
{
	int BUFFER_SIZE = 1;
	static char *store[1024];
	char buf[BUFFER_SIZE + 1];
	int bytesread;
	char *newline;
	char *tmp;
	char **extra;

	if (fd < 0 || line == NULL)
		return (-1);
	
	//BEFORE NEW LINE
	while ((bytesread = read (fd, buf, BUFFER_SIZE)) > 0)
	{
		printf("STORE[FD]: %s\n", store[fd]);
		buf[bytesread] = '\0';
		if (store[fd] == NULL)
			store[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(store[fd], buf);
			free(store[fd]);
			store[fd] = tmp;
		}
		if (ft_strchr(buf, '\n'))
		{
			*line = ft_strdup(store[fd]);
			free(store[fd]);
			printf("%c", '#');
			printf("STORE[FD]: %s\n", store[fd]);
			return (1);
		}
	}
	//DEALING WITH SURPLUS


	//EOF
	if ((store[fd] != NULL) && !bytesread)
		{
			*line = ft_strdup(store[fd]);
			free(store[fd]);
			return (0);
		}
	
}
	

	//	//while (!(ft_strchr(buf, '\n')) && bytesread)
	//	//{
	//	//	
	//	//	else
	//	//	{
	//	//		*tmp = ft_strjoin(store[fd], buf);
	//	//		free(store[fd]);
	//	//		store[fd] = *tmp;	
	//	//	}
	//	//	printf("STORE[FD]: %s\n", store[fd]);
	//	//}
	//	if (store[fd] != NULL)
	//	{	
	//		newline = ft_strdup(store[fd]);
	//		free(store[fd]);
	//		*tmp = ft_strjoin(newline, buf);
	//		store[fd] = ft_strdup(*tmp);			
	//	}
	//	if (ft_strchr(buf, '\n'))
	//	{
	//		tmp = ft_split(buf, '\n');
	//		newline = ft_strchr(buf, '\n');
	//		break;
	//	}
	//	return (1);
	//}
	//	
	//while (store[fd] != NULL)
	//{
	//	tmp = ft_split(store[fd], '\n');
	//	*line = *tmp;
	//	newline = ft_strdup(++store[fd]);
	//	newline = ft_strchr(newline, '\n');
	//	store[fd] = ft_strdup(newline);
	//	*tmp = newline;
	//	if (!(ft_strchr(*++tmp, '\n')))
	//		return (1);
	//}
	//if ((store[fd] != NULL) && !bytesread)
	//{
	//	*line = ft_strdup(store[fd]);
	//	free(store[fd]);
	//	return (0);
	//}
	//if (store[fd] != NULL)
	//	free(store[fd]);
	//store[fd] = ft_strdup(newline);
	////printf("STORE[FD]: %s\n", store[fd]);
	//*line = *tmp;
	//return (0);







int main (void)
{
	int 	fd;
	char	*line;
	int ret;

	fd = open("abc.txt", O_RDONLY);
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