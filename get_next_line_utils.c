#include "get_next_line.h"

static int	count_words(const char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str++ != c)
			++i;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	*start;
	char	**ret;
	int		i;

	if (!s)
		return (0);
	ret = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ret)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				++s;
			ret[i] = (char *)malloc(sizeof(char) * (s - start + 1));
			ft_strlcpy(ret[i++], start, (s - start + 1));
		}
		if (*s)
			++s;
	}
	ret[i] = NULL;
	return (ret);
}

void	ft_strdel(char **as)
{
	if(!as)
		;
	else
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * size + 1);
		if(!new)
			return (0);
	new[size] = '\0';
	while(size--)
		new[size] = '\0';
	return(new);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		++i;
	return (i);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if(!src && !dst)
		return (0);
	
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int 	len;
	char	*str;

	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if ((char)c == 0)
		return (str);
	return (0);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	char	*ret;
	int		lens1;
	int		lens2;

	if (!s1 || !s2)
		return (ft_strdup(""));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	strjoin = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!strjoin)
		return (0);
	ret = strjoin;
	while (lens1--)
		*strjoin++ = *s1++;
	while (lens2--)
		*strjoin++ = *s2++;
	*strjoin = 0;
	return (ret);
}
