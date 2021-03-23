/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:42:57 by marmota           #+#    #+#             */
/*   Updated: 2021/03/21 16:54:21 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	if (!src && !dst)
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
	int		len;
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
