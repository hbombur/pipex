/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbombur <hbombur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:05:07 by hbombur           #+#    #+#             */
/*   Updated: 2021/10/24 12:05:07 by hbombur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_free(char **arr)
{
	size_t	n;

	n = 0;
	while (arr[n] != NULL)
		free(arr[n++]);
	free(arr);
	return (NULL);
}

size_t	ft_word_count(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			count++;
			i++;
			while (str[i] == c)
				i++;
		}
		else
		{
			i++;
			if (str[i] == '\0')
				count++;
		}
	}
	return (count);
}

size_t	ft_pointer(char *str, char c)
{
	size_t	j;

	j = 0;
	while (str[j] != c && str[j] != '\0')
		j++;
	return (j);
}

char	**ft_make_arr(size_t j, char *str, char c, char **arr)
{
	size_t	n;
	size_t	len;

	n = 0;
	len = 0;
	while (j > 0)
	{
		while (*str == c)
			str++;
		len = ft_pointer(str, c);
		arr[n] = ft_substr(str, 0, len);
		if (arr[n++] == NULL)
			return (ft_free(arr));
		while (len--)
			str++;
		j--;
	}
	arr[n] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	n;
	char	**arr;
	char	*str;

	n = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	j = ft_word_count(str, c);
	arr = (char **)malloc((j + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_make_arr(j, str, c, arr);
	return (arr);
}
