/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:43:55 by hbombur           #+#    #+#             */
/*   Updated: 2022/03/23 18:34:35 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			write(fd, &str[i], 1);
			i++;
		}
	}
}

int	ft_strncmp(const char	*s1, const char	*s2, size_t	n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*dst;
	size_t	l;
	int		i;

	i = 0;
	if (s2 == 0 || s1 == 0)
		return (0);
	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *) malloc(l);
	if (!dst)
		return (NULL);
	l = 0;
	while (s1[i] != '\0')
		dst[l++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		dst[l++] = s2[i++];
	dst[l] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lenstr;
	size_t	l;
	char	*dst;

	l = 0;
	if (s == 0)
		return (NULL);
	lenstr = ft_strlen(s);
	if (len > lenstr - start)
		len = lenstr - start;
	dst = (char *)malloc (len + 1);
	if (!dst)
		return (NULL);
	while (s && l < len && start < lenstr)
		dst[l++] = s[start++];
	dst[l] = '\0';
	return (dst);
}
