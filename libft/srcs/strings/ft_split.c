/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:45:34 by yguinio           #+#    #+#             */
/*   Updated: 2025/01/29 13:29:17 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *str, char c)
{
	size_t	count;
	size_t	i;
	int		is_word;

	count = 0;
	i = 0;
	is_word = 0;
	while (str[i])
	{
		if (str[i] == c)
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_wordlen(char const *str, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
			{
				len++;
				i++;
			}
			return (len);
		}
		i++;
	}
	return (len);
}

static char	**ft_clean(char **array, size_t siz)
{
	size_t	i;

	i = 0;
	while (i < siz)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t			i;
	size_t			j;
	size_t const	word_count = ft_countword(s, c);
	char			**array;

	i = 0;
	j = 0;
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	array[word_count] = 0;
	while (i < word_count)
	{
		while (s[j] == c)
			j++;
		array[i] = (char *)malloc(sizeof(char) * ((ft_wordlen(s + j, c) + 1)));
		if (!array[i])
			return (ft_clean(array, i));
		ft_strlcpy(array[i], s + j, (ft_wordlen(s + j, c) + 1));
		j += ft_wordlen(s + j, c) + 1;
		i++;
	}
	return (array);
}
