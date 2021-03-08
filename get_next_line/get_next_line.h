#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int		get_next_line(const int fd, char **line);


#include <stdio.h>
#include <fcntl.h> // open
#include <unistd.h> // read
#include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
char	**ft_split(char const *s, char c);

#endif